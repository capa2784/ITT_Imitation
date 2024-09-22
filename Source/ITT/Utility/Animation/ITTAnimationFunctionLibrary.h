// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ITTDefine_Animation.h"
#include "ITTAnimationFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTAnimationFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// ========== Anim Data ========== //
	UFUNCTION(Category = ITT, BlueprintPure, meta = (BlueprintThreadSafe))
	static class UAnimSequenceBase* GetRandomAnimAnimSequence(const FITTAnimSequencesData& AnimSequencesData);
	// =============================== //
};