// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTGameMode_InGame.h"

#include "Player/PlayerController/ITTPlayerController_InGame.h"
#include "Character/Player/ITTCharacter_Player.h"


AITTGameMode_InGame::AITTGameMode_InGame()
{
}


void AITTGameMode_InGame::BeginPlay()
{
	Super::BeginPlay();

	AdjustPlayer();
}


// ========== Player ========== //
UClass* AITTGameMode_InGame::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	if (AITTPlayerController_InGame* ITTPlayerController = Cast<AITTPlayerController_InGame>(InController))
	{
		if (PlayerCharacterClasses.Contains(ITTPlayerController->GetPlayerCharacter()))
		{
			return *PlayerCharacterClasses.Find(ITTPlayerController->GetPlayerCharacter());
		}
	}

	return nullptr;
}
// ============================ //