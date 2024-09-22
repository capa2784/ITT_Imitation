// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTDefine_GameBase.generated.h"


// ==================== Enum ==================== //
// ========== GameInstance ========== //
UENUM()
enum class EITTLaunchProcess : uint8
{
	None = 0,
 
	CreateBasicUtility,
	CreateGameManager,
	RegisterTick,
	ProcessFinished,

	End
};
// ================================== //


// ========== Scene ========== //
UENUM()
enum class EITTSceneType : uint32
{
	// MainScene * 8 / SubScene * 8 / Detail1 * 8 / Detail2 * 8
	
	None = 0b0,
};

UENUM()
enum class EITTLoadingType : uint8
{
	None = 0,
};
// =========================== //
// ============================================== //


// ==================== Delegate ==================== //
// ========== Level ========== //
DECLARE_DELEGATE_OneParam(FITTOnLoadLevelComplete, const FString&);
// =========================== //
// ================================================== //