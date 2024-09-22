// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/SubAnimation/ITTSubAnimInstance.h"
#include "Character/ITTDefine_Character.h"
#include "ITTSubAnimInstance_Character.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTSubAnimInstance_Character : public UITTSubAnimInstance
{
	GENERATED_BODY()

public:
	UITTSubAnimInstance_Character();

	
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativePostEvaluateAnimation() override;
	virtual void NativeUninitializeAnimation() override;
	virtual void NativeBeginPlay() override;

	
private:
	void InitializeOwner();
	
	void InitializeOwnerComponent();

	
protected:
	// ========== Movement Mode ========== //
	virtual void InitializeCharacterMovementMode();
	// =================================== //


	// ========== SubAnimation ========== //
	virtual void InitializeSubAnimData();
	// ================================== //

	
protected:
	TWeakObjectPtr<class AITTCharacterBase> CharacterBase;

	TWeakObjectPtr<class UITTAnimationHelperComponent> AnimationHelperComponent;
	
	TWeakObjectPtr<class UITTCharacterMovementComponent> CharacterMovementComponent;
	
	TWeakObjectPtr<class UITTCharacterStatComponent> CharacterStatComponent;

	TWeakObjectPtr<class UITTStateMachine> MovementModeMachine;


	// ========== Anim Data ========== //
	UPROPERTY(Category = ITT, BlueprintReadOnly)
	class UITTData_SubAnim* SubAnimData;
	// =============================== //

	
	// ========== Movement Mode ========== //
	UPROPERTY(Category = ITT, BlueprintReadOnly)
	FITTMovementMode PreMovementMode;
	
	UPROPERTY(Category = ITT, BlueprintReadOnly)
	FITTMovementMode CurrentMovementMode;

	UPROPERTY(Category = ITT, BlueprintReadOnly)
	FITTMovementMode NextMovementMode;
	// =================================== //
};
