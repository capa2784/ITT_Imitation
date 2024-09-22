// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Animation/ITTDefine_Animation.h"
#include "ITTData_SubAnim.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTData_SubAnim : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UAnimInstance> SubAnimInstanceClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bReInitAnimWhenRequested;
};
