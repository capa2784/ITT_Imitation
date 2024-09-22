// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameBase/ITTDefine_GameBase.h"
#include "ITTLoadingHelper.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTLoadingHelper : public UObject
{
	GENERATED_BODY()

public:
	UITTLoadingHelper();
	
	
	void Initialize();
	void Deinitialize();

	
	// ========== Loading ========== //
	bool StartLoading(EITTLoadingType LoadingType);
	void EndLoading(EITTLoadingType LoadingType);
	// ============================= //
	
	
private:
	bool bInitialized;
};
