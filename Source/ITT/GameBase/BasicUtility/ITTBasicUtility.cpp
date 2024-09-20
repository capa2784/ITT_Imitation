// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTBasicUtility.h"

#include "ITTGameConfig.h"
#include "GameBase/GameInstance/ITTGameInstanceBase.h"


TObjectPtr<UITTBasicUtility> UITTBasicUtility::Instance = nullptr;


UITTBasicUtility::UITTBasicUtility()
{
}


// ========== Instance ========== //
TObjectPtr<UITTBasicUtility> UITTBasicUtility::CreateInstance()
{
	Instance = ITTNewObject<UITTBasicUtility>();
	if (Instance)
	{
		Instance->AddToRoot();
	}
	
	return Instance;
}

void UITTBasicUtility::DestroyInstance()
{
	if (IsValid(Instance))
	{
		Instance->RemoveFromRoot();
		ITTDeleteObject(Instance);
	}
}

bool UITTBasicUtility::Initialize(UITTGameInstanceBase* _ITTGameInstance)
{
	ITTGameInstance = _ITTGameInstance;
	Instance->CreateCompositionObjects();
	
	return true;
}

void UITTBasicUtility::Finalize()
{
	ITTGameInstance = nullptr;
	Instance->DestroyCompositionObjects();
}
// ============================== //


// ========== Composition ========== //
void UITTBasicUtility::CreateCompositionObjects()
{
	ITTGameConfig = ITTNewObject<UITTGameConfig>();
	if (ITTGameConfig)
	{
		ITTGameConfig->AddToRoot();
	}
}

void UITTBasicUtility::DestroyCompositionObjects()
{
	if (IsValid(ITTGameConfig))
	{
		ITTGameConfig->RemoveFromRoot();
		ITTDeleteObject(ITTGameConfig);
	}
}
// ================================= //


// ==================== Getter ==================== //
// ========== BasicUtility ========== //
TWeakObjectPtr<UITTGameInstanceBase> UITTBasicUtility::GetITTGameInstance()
{
	if (IsValid(Instance))
	{
		return Instance->ITTGameInstance;
	}

	return nullptr;
}

UWorld* UITTBasicUtility::GetITTWorld()
{
	TWeakObjectPtr<UITTGameInstanceBase> GameInstance = GetITTGameInstance();
	if (GameInstance != nullptr)
	{
		return GameInstance->GetWorld();
	}

	return nullptr;
}
// ================================== //


// ========== GameConfig ========== //
const FString& UITTBasicUtility::GetTableListPath()
{
	ITTCHECK(Instance);
	ITTCHECK(Instance->ITTGameConfig);
	
	return Instance->ITTGameConfig->GetTableListPath();
}
// ================================ //
// ================================================ //