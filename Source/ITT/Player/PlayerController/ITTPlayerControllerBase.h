// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character/ITTDefine_Character.h"
#include "ITTPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API AITTPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	AITTPlayerControllerBase(const FObjectInitializer& ObjectInitializer);

	
	virtual void PreInitialize(class ULocalPlayer* LocalPlayer);


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
