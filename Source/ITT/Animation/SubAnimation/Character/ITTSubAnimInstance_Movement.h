// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTSubAnimInstance_Character.h"
#include "ITTSubAnimInstance_Movement.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTSubAnimInstance_Movement : public UITTSubAnimInstance_Character
{
	GENERATED_BODY()

public:
	UITTSubAnimInstance_Movement();

	
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;

	
protected:
	// ========== Movement Value ========== //
	virtual void InitializeMovementValue();
	
	virtual void UpdateMovementValue(float DeltaSeconds);
	// ==================================== //

	
protected:
	// ========== Movement Value ========== //
	// ----- No Update ----- //
	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float MinWalkSpeed;
	
	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float MaxJogSpeed;
	

	// ----- Update ----- //
	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bShouldMove;

	
	// -- Speed -- //
	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FVector Velocity;
	
	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float GroundSpeed;

	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float GroundSpeedPerMaxJogSpeed;

	
	// -- Direction -- //
	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FRotator ControlRotation;

	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FRotator ActorRotation;
	
	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FVector ForwardVector;

	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float FaceYaw_Cached;

	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float FaceYaw_Target;

	UPROPERTY(Category = ITTAnim, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float FaceYaw;
	// ==================================== //
};
