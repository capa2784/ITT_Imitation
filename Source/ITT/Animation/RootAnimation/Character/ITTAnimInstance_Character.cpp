// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTAnimInstance_Character.h"

#include "Character/ITTCharacterBase.h"
#include "Component/Character/Animation/ITTAnimationHelperComponent.h"
#include "Component/Character/Movement/ITTCharacterMovementComponent.h"
#include "StateMachine/ITTStateMachine.h"


UITTAnimInstance_Character::UITTAnimInstance_Character()
{
}


void UITTAnimInstance_Character::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	InitializeOwner();
}

void UITTAnimInstance_Character::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	UpdateCharacterMovementMode();
}

void UITTAnimInstance_Character::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}

void UITTAnimInstance_Character::NativePostEvaluateAnimation()
{
	Super::NativePostEvaluateAnimation();
}

void UITTAnimInstance_Character::NativeUninitializeAnimation()
{
	Super::NativeUninitializeAnimation();
}

void UITTAnimInstance_Character::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	InitializeOwnerComponent();
}


void UITTAnimInstance_Character::InitializeOwner()
{
	CharacterBase = Cast<AITTCharacterBase>(GetOwningActor());
}

void UITTAnimInstance_Character::InitializeOwnerComponent()
{
	if (CharacterBase != nullptr)
	{
		AnimationHelperComponent = CharacterBase->GetAnimationHelperComponent();
		
		CharacterMovementComponent = Cast<UITTCharacterMovementComponent>(CharacterBase->GetCharacterMovement());

		if (CharacterMovementComponent != nullptr)
		{
			MovementModeMachine = CharacterMovementComponent->GetMovementModeMachine();
		}
	}
}


// ========== Movement Mode ========== //
void UITTAnimInstance_Character::UpdateCharacterMovementMode()
{
	if (CharacterBase != nullptr && CharacterMovementComponent != nullptr && MovementModeMachine != nullptr)
	{
		FITTMovementMode MovementMode_Temp = CurrentMovementMode;
		
		CurrentMovementMode.SetUsingFullMode(MovementModeMachine->GetCurrentStateId());

		if (MovementMode_Temp != CurrentMovementMode)
		{
			UpdateSubAnimation();
		}
	}
}
// =================================== //


// ========== SubAnimation ========== //
void UITTAnimInstance_Character::UpdateSubAnimation()
{
	if (TSubclassOf<UAnimInstance> SubAnimInstanceClass = GetSubAnimInstanceClass(CurrentMovementMode))
	{
		LinkAnimClassLayers(SubAnimInstanceClass);
	}
}

TSubclassOf<UAnimInstance> UITTAnimInstance_Character::GetSubAnimInstanceClass(
	const FITTMovementMode& MovementMode) const
{
	if (CharacterBase != nullptr && AnimationHelperComponent != nullptr)
	{
		return AnimationHelperComponent->GetSubAnimInstanceClass(MovementMode);
	}

	return nullptr;
}
// ================================== //