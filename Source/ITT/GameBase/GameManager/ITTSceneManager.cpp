// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTSceneManager.h"

#include "ITTUtilityFunctionLibrary.h"

#include "ITTTableManager.h"
#include "Data/Table/Tables/GameBase/ITTTable_Scene.h"

#include "Scene/Helper/ITTLoadingHelper.h"
#include "Scene/Helper/ITTSceneHelper.h"

#include "StateMachine/ITTStateMachine.h"
#include "Scene/ITTSceneBase.h"

#include "ITTLevelManager.h"


UITTSceneManager::UITTSceneManager()
{
}


void UITTSceneManager::BuiltInInitialize()
{
	CreateHelper();
	CreateSceneStateMachine();
}

void UITTSceneManager::Initialize()
{
}

void UITTSceneManager::PostInitialize()
{
//#if !WITH_EDITOR
	LoadFirstScene();
//#endif // WITH_EDITOR
}

void UITTSceneManager::PreFinalize()
{
}

void UITTSceneManager::Finalize()
{
}

void UITTSceneManager::BuiltInFinalize()
{
	DestroyScene(CurrentScene);
	DestroySceneStateMachine();
	DestroyHelper();
}

void UITTSceneManager::Tick(float DeltaTime)
{
	if (CurrentScene)
	{
		CurrentScene->Tick(DeltaTime);
	}
}


// ========== Helper ========== //
void UITTSceneManager::CreateHelper()
{
	SceneHelper = ITTNewObject<UITTSceneHelper>(this, UITTSceneHelper::StaticClass());
	if (SceneHelper)
	{
		SceneHelper->AddToRoot();
		SceneHelper->Initialize();
	}
	
	LoadingHelper = ITTNewObject<UITTLoadingHelper>(this, UITTLoadingHelper::StaticClass());
	if (LoadingHelper)
	{
		LoadingHelper->AddToRoot();
		LoadingHelper->Initialize();
	}
}

void UITTSceneManager::DestroyHelper()
{
	if (IsValid(LoadingHelper))
	{
		LoadingHelper->Deinitialize();
		LoadingHelper->RemoveFromRoot();
		ITTDeleteObject(LoadingHelper);
	}

	if (IsValid(SceneHelper))
	{
		SceneHelper->Deinitialize();
		SceneHelper->RemoveFromRoot();
		ITTDeleteObject(SceneHelper);
	}
}
// ============================ //


// ========== Scene State Machine ========== //
void UITTSceneManager::CreateSceneStateMachine()
{
	SceneStateMachine = ITTNewObject<UITTStateMachine>(this, UITTStateMachine::StaticClass());

	if (SceneStateMachine)
	{
		SceneStateMachine->AddToRoot();
		SceneStateMachine->BuiltInInitialize(FName("SceneStateMachine"));
		SceneStateMachine->OnChangeStateDelegate = FITTOnChangeStateDelegate::CreateUObject(this, &UITTSceneManager::OnChangeSceneState);
	}
}

void UITTSceneManager::DestroySceneStateMachine()
{
	if (IsValid(SceneStateMachine))
	{
		SceneStateMachine->RemoveFromRoot();
		ITTDeleteObject(SceneStateMachine);
	}
}

void UITTSceneManager::ChangeScene(EITTSceneType NextSceneType, EITTLoadingType LoadingType, bool bImmediately)
{
	if (IsValid(CurrentScene))
	{
		SceneStateMachine->SetNextState(static_cast<uint32>(NextSceneType), false);
		
		CurrentScene->OnReadyToFinishDelegate = FITTOnReadyToFinishDelegate::CreateLambda([this, LoadingType]()
		{
			ITTCHECK(IsValid(this));
			ChangeSceneState(LoadingType);
		});

		if (bImmediately)
		{
			CurrentScene->PrepareToFinish_Immediately(NextSceneType, LoadingType);
		}
		else
		{
			CurrentScene->PrepareToFinish(NextSceneType, LoadingType);
		}
	}
	else
	{
		SceneStateMachine->SetNextState(static_cast<uint32>(NextSceneType), true);
	}
}

void UITTSceneManager::ChangeSceneState(EITTLoadingType LoadingType)
{
	// Loading start
	bool bStartLoading = LoadingHelper->StartLoading(LoadingType);

	// Change scene
	SceneStateMachine->ChangeToNextState();

	// Loading end
	if (EndLoadingDelegate.IsBound())
	{
		EndLoadingDelegate.Unbind();
	}
	
	if (bStartLoading)
	{
		EndLoadingDelegate = FITTEndLoadingDelegate::CreateLambda([this, LoadingType]()
		{
			if (!IsValid(LoadingHelper))
			{
				return;
			}
		
			LoadingHelper->EndLoading(LoadingType);
		});
	}
}

void UITTSceneManager::OnChangeSceneState(int64 PreviousSceneId, int64 CurrentSceneId)
{
	ITTCHECK(CurrentSceneId > 0);
	
	ITTCHECK(IsValid(TableMgr));
	ITTCHECK(IsValid(LevelMgr));

	const FName& SceneTableName = UITTTable_Scene::GetTableName();
	UITTTable_Scene* ITTTable_Scene = TableMgr->GetITTTable<UITTTable_Scene>(SceneTableName);
	ITTCHECK(IsValid(ITTTable_Scene));
	
	TWeakObjectPtr<UITTSceneBase> PreviousScene = CurrentScene;
	EITTSceneType PreviousSceneType = static_cast<EITTSceneType>(PreviousSceneId);

	if (PreviousScene != nullptr && PreviousSceneType != PreviousScene->GetSceneType())
	{
		ITTENSUREF(false, TEXT("[%s] Previous scene and machine previous id do not match, [PreviousSceneId : %d], [MachinePreviousSceneId : %d]"),
				*ITTSTRING_CLASS_FUNC, static_cast<int64>(PreviousScene->GetSceneType()), PreviousSceneId);
	}
	
	EITTSceneType CurrentSceneType = static_cast<EITTSceneType>(CurrentSceneId);

	// Create scene
	CurrentScene = CreateScene(CurrentSceneType);

	// Transfer data
	if (PreviousScene != nullptr)
	{
		PreviousScene->TransferData(CurrentScene);
	}

	// Open Level
	FITTOnLoadLevelComplete OnLoadLevelComplete;
	OnLoadLevelComplete.BindLambda([this, CurrentSceneType](const FString& Context)
	{
		CurrentScene->Initialize(CurrentSceneType);
		bool bDelegateBound = EndLoadingDelegate.ExecuteIfBound();
	});

	bool bOpenLevel = TryOpenLevel(OnLoadLevelComplete, CurrentSceneType,  PreviousSceneType);
	if (!bOpenLevel)
	{
		OnLoadLevelComplete.ExecuteIfBound(FString());
	}

	// Destroy previous scene
	DestroyScene(PreviousScene);
}

TObjectPtr<UITTSceneBase> UITTSceneManager::CreateScene(EITTSceneType SceneType)
{
	ITTCHECK(IsValid(TableMgr));

	const FName& SceneTableName = UITTTable_Scene::GetTableName();
	UITTTable_Scene* ITTTable_Scene = TableMgr->GetITTTable<UITTTable_Scene>(SceneTableName);
	ITTCHECK(IsValid(ITTTable_Scene));
	
	TWeakObjectPtr<UClass> SceneClass = ITTTable_Scene->GetSceneClass(SceneType);
	ITTCHECK(SceneClass != nullptr);
	
	TObjectPtr<UITTSceneBase> NewScene = ITTNewObject<UITTSceneBase>(this, SceneClass.Get());
	NewScene->AddToRoot();

	return NewScene;
}

void UITTSceneManager::DestroyScene(TWeakObjectPtr<UITTSceneBase> Scene)
{
	if (Scene != nullptr)
	{
		Scene->Finalize();
		Scene->RemoveFromRoot();
		ITTDeleteObject(Scene);
	}
}

bool UITTSceneManager::TryOpenLevel(const FITTOnLoadLevelComplete& Delegate, EITTSceneType CurrentSceneType, EITTSceneType PreviousSceneType)
{
	ITTCHECK(IsValid(TableMgr));

	const FName& SceneTableName = UITTTable_Scene::GetTableName();
	UITTTable_Scene* ITTTable_Scene = TableMgr->GetITTTable<UITTTable_Scene>(SceneTableName);
	ITTCHECK(IsValid(ITTTable_Scene));
	
	const FName& CurrentSceneLevelName = ITTTable_Scene->GetSceneLevelName(CurrentSceneType);
	const FName& PreviousSceneLevelName = PreviousSceneType != EITTSceneType::None ? ITTTable_Scene->GetSceneLevelName(PreviousSceneType) : FName();

	if (CurrentSceneLevelName != FName() && CurrentSceneLevelName != PreviousSceneLevelName)
	{
		LevelMgr->OpenLevelByTable(Delegate, CurrentSceneLevelName);
		return true;
	}

	return false;
}
// ========================================= //


// ========== Scene ========== //
void UITTSceneManager::LoadFirstScene()
{
	ITTCHECK(SceneHelper);
	
	ChangeScene(SceneHelper->GetFirstSceneType(), EITTLoadingType::None, true);
}
// =========================== //