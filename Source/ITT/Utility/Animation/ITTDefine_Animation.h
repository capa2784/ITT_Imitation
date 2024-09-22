// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTDefine_Animation.generated.h"


// ==================== Struct ==================== //
// ========== Anim Data ========== //
// -- AnimSequence -- //
USTRUCT(Blueprintable)
struct FITTAnimSequenceData
{
	GENERATED_BODY()

	FITTAnimSequenceData()
		: bLoop(false)
	{
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class UAnimSequenceBase> ObjectPtr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bLoop;
};

USTRUCT(Blueprintable)
struct FITTAnimSequencesDataElement
{
	GENERATED_BODY()

	FITTAnimSequencesDataElement()
		: Probability(0.f)
	{
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class UAnimSequenceBase> ObjectPtr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Probability;
};

USTRUCT(Blueprintable)
struct FITTAnimSequencesData
{
	GENERATED_BODY()

	FITTAnimSequencesData()
		: bPickHighestProbabilityOnInit(true), bPickHighestProabilityAfterLowProbability(true), bLoop(true)
	{
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FITTAnimSequencesDataElement> AnimSequences;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bPickHighestProbabilityOnInit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bPickHighestProabilityAfterLowProbability;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bLoop;
};


// -- BlendSpace -- //
USTRUCT(Blueprintable)
struct FITTBlendSpaceData
{
	GENERATED_BODY()

	FITTBlendSpaceData()
		: bInitializeToCurrentInputValues(false), bLoop(true)
	{
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class UBlendSpace> ObjectPtr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bInitializeToCurrentInputValues;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bLoop;
};
// =============================== //
// ================================================ //