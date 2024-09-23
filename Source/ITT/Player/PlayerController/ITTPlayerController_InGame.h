// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTPlayerControllerBase.h"
#include "Character/ITTDefine_Character.h"
#include "ITTPlayerController_InGame.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API AITTPlayerController_InGame : public AITTPlayerControllerBase
{
	GENERATED_BODY()

public:
	AITTPlayerController_InGame(const FObjectInitializer& ObjectInitializer);
	

	// ==================== Getter ==================== //
	// ========== Character ========== //
	EITTCharacter_Player GetPlayerCharacter() const { return PlayerCharacter; }
	// =============================== //
	// ================================================ //

	
protected:
	// ========== Character ========== //
	UPROPERTY(Category = ITT, EditAnywhere)
	EITTCharacter_Player PlayerCharacter;
	// =============================== //
};
