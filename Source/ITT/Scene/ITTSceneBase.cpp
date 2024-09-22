// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTSceneBase.h"

#include "ITTUtilityFunctionLibrary.h"


UITTSceneBase::UITTSceneBase()
	: SceneType(EITTSceneType::None)
{
}


void UITTSceneBase::Initialize(EITTSceneType _SceneType)
{
	SceneType = _SceneType;

	FString SceneTypeName = UITTUtilityFunctionLibrary::ConvertEnumToString(FString("EITTSceneType"), SceneType);
	ITTLOG(Log, TEXT("[%s] Initialize scene [SceneType : %s]"), *ITTSTRING_CLASS_FUNC, *SceneTypeName);
}

void UITTSceneBase::Finalize()
{
	FString SceneTypeName = UITTUtilityFunctionLibrary::ConvertEnumToString(FString("EITTSceneType"), SceneType);
	ITTLOG(Log, TEXT("[%s] Finalize scene [SceneType : %s]"), *ITTSTRING_CLASS_FUNC, *SceneTypeName);
}

void UITTSceneBase::Tick(float DeltaTime)
{
}


// ========== Finish ========== //
void UITTSceneBase::PrepareToFinish(EITTSceneType NextSceneType, EITTLoadingType LoadingType)
{
	bool bDelegateBound = OnReadyToFinishDelegate.ExecuteIfBound();	// Call ITTSceneManager::ChangeSceneState()
	if (!bDelegateBound)
	{
		FString CurrentSceneTypeName = UITTUtilityFunctionLibrary::ConvertEnumToString(TEXT("EITTSceneType"), SceneType);
		FString NextSceneTypeName = UITTUtilityFunctionLibrary::ConvertEnumToString(TEXT("EITTSceneType"), NextSceneType);
		ITTLOG(Error, TEXT("[%s] OnReadyToFinishDelegate isn't bound [CurrentSceneType : %s] [NextSceneType : %s]")
			, *ITTSTRING_CLASS_FUNC, *CurrentSceneTypeName, *NextSceneTypeName);
	}
}

void UITTSceneBase::PrepareToFinish_Immediately(EITTSceneType NextSceneType, EITTLoadingType LoadingType)
{
	bool bDelegateBound = OnReadyToFinishDelegate.ExecuteIfBound();	// Call ITTSceneManager::ChangeSceneState()
	if (!bDelegateBound)
	{
		FString CurrentSceneTypeName = UITTUtilityFunctionLibrary::ConvertEnumToString(TEXT("EITTSceneType"), SceneType);
		FString NextSceneTypeName = UITTUtilityFunctionLibrary::ConvertEnumToString(TEXT("EITTSceneType"), NextSceneType);
		ITTLOG(Error, TEXT("[%s] OnReadyToFinishDelegate isn't bound [CurrentSceneType : %s] [NextSceneType : %s]")
			, *ITTSTRING_CLASS_FUNC, *CurrentSceneTypeName, *NextSceneTypeName);
	}
}
// ============================ //