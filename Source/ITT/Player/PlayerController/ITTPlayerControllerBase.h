// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
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
};
