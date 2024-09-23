// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
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
};
