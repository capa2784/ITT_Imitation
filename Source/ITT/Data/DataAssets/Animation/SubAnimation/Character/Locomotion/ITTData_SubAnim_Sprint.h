// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/DataAssets/Animation/SubAnimation/ITTData_SubAnim.h"
#include "ITTData_SubAnim_Sprint.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ITT_API UITTData_SubAnim_Sprint : public UITTData_SubAnim
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData SprintStart;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTAnimSequenceData SprintFromLanding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTBlendSpaceData Sprint;
};
