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
// ============================================== //