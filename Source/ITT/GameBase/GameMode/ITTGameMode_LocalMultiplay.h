// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTGameModeBase.h"
#include "ITTGameMode_LocalMultiplay.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API AITTGameMode_LocalMultiplay : public AITTGameModeBase
{
	GENERATED_BODY()

public:
	AITTGameMode_LocalMultiplay();

	
protected:
	// ========== Player ========== //
	virtual void AdjustPlayer() override;
	// ============================ //
};
