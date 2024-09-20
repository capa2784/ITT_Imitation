// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTPlayerControllerBase.h"
#include "ITTPlayerController_LocalMultiplay.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API AITTPlayerController_LocalMultiplay : public AITTPlayerControllerBase
{
	GENERATED_BODY()

public:
	AITTPlayerController_LocalMultiplay(const FObjectInitializer& ObjectInitializer);


	virtual void PreInitialize(class ULocalPlayer* LocalPlayer) override;
};