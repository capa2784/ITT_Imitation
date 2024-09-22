// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameBase/ITTDefine_GameBase.h"
#include "ITTSceneHelper.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTSceneHelper : public UObject
{
	GENERATED_BODY()

public:
	UITTSceneHelper();

	
	void Initialize();
	void Deinitialize();

	
	// ========== Scene ========== //
	EITTSceneType GetFirstSceneType() const;
	// =========================== //

	
private:
	bool bInitialized;
};
