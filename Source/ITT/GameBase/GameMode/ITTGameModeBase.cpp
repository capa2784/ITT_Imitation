// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTGameModeBase.h"

#include "Engine/LocalPlayer.h"
#include "GameFramework/GameSession.h"

#include "Player/PlayerController/ITTPlayerControllerBase.h"


AITTGameModeBase::AITTGameModeBase()
{
}


APlayerController* AITTGameModeBase::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal,
	const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	if (GameSession == nullptr)
	{
		ErrorMessage = TEXT("Failed to spawn player controller, GameSession is null");
		return nullptr;
	}

	ErrorMessage = GameSession->ApproveLogin(Options);
	if (!ErrorMessage.IsEmpty())
	{
		return nullptr;
	}

	APlayerController* const NewPlayerController = SpawnPlayerController(InRemoteRole, Options);
	if (NewPlayerController == nullptr)
	{
		// Handle spawn failure.
		UE_LOG(LogGameMode, Log, TEXT("Login: Couldn't spawn player controller of class %s"), PlayerControllerClass ? *PlayerControllerClass->GetName() : TEXT("NULL"));
		ErrorMessage = FString::Printf(TEXT("Failed to spawn player controller"));
		return nullptr;
	}

	//	PreInitialize player controller
	if (AITTPlayerControllerBase* ITTPlayerController = Cast<AITTPlayerControllerBase>(NewPlayerController))
	{
		ITTPlayerController->PreInitialize(Cast<ULocalPlayer>(NewPlayer));
	}
	
	// Customize incoming player based on URL options
	ErrorMessage = InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);
	if (!ErrorMessage.IsEmpty())
	{
		NewPlayerController->Destroy();
		return nullptr;
	}

	return NewPlayerController;
}