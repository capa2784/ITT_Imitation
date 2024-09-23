// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTGameModeBase.h"
#include "Character/ITTDefine_Character.h"
#include "ITTGameMode_InGame.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API AITTGameMode_InGame : public AITTGameModeBase
{
	GENERATED_BODY()

public:
	AITTGameMode_InGame();


protected:
	virtual void BeginPlay() override;


public:
	// ========== Player ========== //
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

protected:
	virtual void AdjustPlayer() {}
	// ============================ //

	
protected:
	// ========== Player ========== //
	UPROPERTY(Category = ITT, EditAnywhere)
	TMap<EITTCharacter_Player, TSubclassOf<class AITTCharacter_Player>> PlayerCharacterClasses;
	// ============================ //
};
