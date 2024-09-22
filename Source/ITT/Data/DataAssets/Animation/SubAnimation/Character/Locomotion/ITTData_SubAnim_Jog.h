// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/DataAssets/Animation/SubAnimation/ITTData_SubAnim.h"
#include "ITTData_SubAnim_Jog.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ITT_API UITTData_SubAnim_Jog : public UITTData_SubAnim
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bUse180;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequencesData IdleAnimations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool UseIdleGestures;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequencesData IdleGestures;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData BigGesturesStart;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData BigGesturesMh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bUseActionIdle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequencesData ActionIdleAnimations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData IdleToAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData ActionToIdle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequencesData ExhaustedIdleAnimations;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData IdleToExhausted;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData ExhaustedToIdle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ActionIdleTriggerTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ExhaustedIdleTriggerTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTBlendSpaceData StartAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTBlendSpaceData StartInMotionAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTBlendSpaceData StartInMotion_Var2_Animation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTBlendSpaceData ActionStartAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTBlendSpaceData ExhaustedStartAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData StopAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData GoToStopAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData ActionStopAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData ExhaustedStopAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData EasyStopAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bUseMovementBlendSpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequencesData MovementAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTBlendSpaceData MovementBlendSpace;
};