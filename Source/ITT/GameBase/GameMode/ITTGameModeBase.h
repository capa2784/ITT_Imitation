// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Character/ITTDefine_Character.h"
#include "ITTGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API AITTGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AITTGameModeBase();

	
	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

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
