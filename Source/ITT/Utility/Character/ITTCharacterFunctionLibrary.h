// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ITTDefine_Character.h"
#include "ITTCharacterFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTCharacterFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// ========== Movement Mode ========== //
	static bool CheckMovementModeValid(const FITTMovementMode& ITTMovementMode);
	// =================================== //
};
