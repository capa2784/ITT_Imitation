// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ITTSubAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTSubAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UITTSubAnimInstance();

	
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;
};
