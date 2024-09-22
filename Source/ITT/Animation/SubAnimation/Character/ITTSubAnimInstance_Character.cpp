// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTSubAnimInstance_Character.h"

#include "Character/ITTCharacterBase.h"
#include "Component/Character/Animation/ITTAnimationHelperComponent.h"
#include "Component/Character/Movement/ITTCharacterMovementComponent.h"
#include "Component/Character/Stat/ITTCharacterStatComponent.h"
#include "StateMachine/ITTStateMachine.h"


UITTSubAnimInstance_Character::UITTSubAnimInstance_Character()
{
}


void UITTSubAnimInstance_Character::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	InitializeOwner();
	InitializeOwnerComponent();
	InitializeCharacterMovementMode();
	InitializeSubAnimData();
}

void UITTSubAnimInstance_Character::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UITTSubAnimInstance_Character::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}

void UITTSubAnimInstance_Character::NativePostEvaluateAnimation()
{
	Super::NativePostEvaluateAnimation();
}

void UITTSubAnimInstance_Character::NativeUninitializeAnimation()
{
	Super::NativeUninitializeAnimation();
}

void UITTSubAnimInstance_Character::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}


// ========== Init ========== //
void UITTSubAnimInstance_Character::InitializeOwner()
{
	CharacterBase = Cast<AITTCharacterBase>(GetOwningActor());
}

void UITTSubAnimInstance_Character::InitializeOwnerComponent()
{
	if (CharacterBase != nullptr)
	{
		AnimationHelperComponent = CharacterBase->GetAnimationHelperComponent();
		
		CharacterMovementComponent = Cast<UITTCharacterMovementComponent>(CharacterBase->GetCharacterMovement());

		if (CharacterMovementComponent != nullptr)
		{
			MovementModeMachine = CharacterMovementComponent->GetMovementModeMachine();
		}

		CharacterStatComponent = CharacterBase->GetCharacterStatComponent();
	}
}

void UITTSubAnimInstance_Character::InitializeCharacterMovementMode()
{
	if (CharacterBase != nullptr && CharacterMovementComponent != nullptr && MovementModeMachine != nullptr)
	{
		PreMovementMode.SetUsingFullMode(MovementModeMachine->GetPreviousStateId());
		CurrentMovementMode.SetUsingFullMode(MovementModeMachine->GetCurrentStateId());
		NextMovementMode.SetUsingFullMode(MovementModeMachine->GetNextStateId());
	}
}

void UITTSubAnimInstance_Character::InitializeSubAnimData()
{
	if (CharacterBase != nullptr && AnimationHelperComponent != nullptr)
	{
		SubAnimData = AnimationHelperComponent->GetSubAnimData(CurrentMovementMode);
	}
}
// ========================== //