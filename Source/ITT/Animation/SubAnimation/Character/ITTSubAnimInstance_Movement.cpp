// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTSubAnimInstance_Movement.h"

#include "Character/ITTCharacterBase.h"
#include "Component/Character/Movement/ITTCharacterMovementComponent.h"
#include "Component/Character/Stat/ITTCharacterStatComponent.h"


UITTSubAnimInstance_Movement::UITTSubAnimInstance_Movement()
{
}


void UITTSubAnimInstance_Movement::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	InitializeMovementValue();
}

void UITTSubAnimInstance_Movement::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	UpdateMovementValue(DeltaSeconds);
}

void UITTSubAnimInstance_Movement::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}

void UITTSubAnimInstance_Movement::NativePostEvaluateAnimation()
{
	Super::NativePostEvaluateAnimation();
}

void UITTSubAnimInstance_Movement::NativeUninitializeAnimation()
{
	Super::NativeUninitializeAnimation();
}

void UITTSubAnimInstance_Movement::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}


// ========== Movement Value ========== //
void UITTSubAnimInstance_Movement::InitializeMovementValue()
{
	if (CharacterBase != nullptr && CharacterStatComponent != nullptr)
	{
		MinWalkSpeed = CharacterStatComponent->GetCharacterStat(EITTCharacterStat::MinWalkSpeed);
		MaxJogSpeed = CharacterStatComponent->GetCharacterStat(EITTCharacterStat::MaxJogSpeed);
	}
}

void UITTSubAnimInstance_Movement::UpdateMovementValue(float DeltaSeconds)
{
	if (CharacterBase != nullptr && CharacterMovementComponent != nullptr)
	{
		bShouldMove = CharacterMovementComponent->GetCurrentAcceleration() != FVector::Zero() && GroundSpeed > MinWalkSpeed;
		ITTLOG(Warning, TEXT("[%s] ShouldMove : %d"), *ITTSTRING_CLASS_FUNC, bShouldMove ? 1 : 0);

		
		// -- Moving -- //
		Velocity = CharacterMovementComponent->Velocity;
		ITTLOG(Warning, TEXT("[%s] Velocity : %f, %f, %f"), *ITTSTRING_CLASS_FUNC, Velocity.X, Velocity.Y, Velocity.Z);
		
		GroundSpeed = Velocity.Size2D();
		ITTLOG(Warning, TEXT("[%s] GroundSpeed : %f"), *ITTSTRING_CLASS_FUNC, GroundSpeed);

		GroundSpeedPerMaxJogSpeed = GroundSpeed / MaxJogSpeed;
		ITTLOG(Warning, TEXT("[%s] GroundSpeedPerMaxJogSpeed : %f"), *ITTSTRING_CLASS_FUNC, GroundSpeedPerMaxJogSpeed);

		
		// -- Direction -- //
		ForwardVector = CharacterBase->GetActorForwardVector();
		ITTLOG(Warning, TEXT("[%s] ForwardVector : %f, %f, %f"), *ITTSTRING_CLASS_FUNC, ForwardVector.X, ForwardVector.Y, ForwardVector.Z);
		
		ControlRotation = CharacterBase->GetControlRotation();
		ITTLOG(Warning, TEXT("[%s] ControlRotation : %f, %f, %f"), *ITTSTRING_CLASS_FUNC, ControlRotation.Roll, ControlRotation.Pitch, ControlRotation.Yaw);
		
		ActorRotation = CharacterBase->GetActorRotation();
		ITTLOG(Warning, TEXT("[%s] ActorRotation : %f, %f, %f"), *ITTSTRING_CLASS_FUNC, ActorRotation.Roll, ActorRotation.Pitch, ActorRotation.Yaw);
		
		FaceYaw_Target = ActorRotation.Yaw - ControlRotation.Yaw;
		if (FaceYaw_Target > 180.f)
		{
			FaceYaw_Target -= 360.f;
		}
		else if (FaceYaw_Target < -180.f)
		{
			FaceYaw_Target += 360.f;
		}

		if (FaceYaw_Target > 80.f || FaceYaw_Target < -80.f)
		{
			FaceYaw_Target = 0.f;
		}
		
		FaceYaw_Target *= 0.66;
		FaceYaw_Target = FMath::Clamp(FaceYaw_Target, -60.f, 60.f);
		ITTLOG(Warning, TEXT("[%s] FaceYaw_Target : %f"), *ITTSTRING_CLASS_FUNC, FaceYaw_Target);

		FaceYaw = FaceYaw_Cached + (FaceYaw_Target - FaceYaw_Cached) * (DeltaSeconds / 0.2f);
		ITTLOG(Warning, TEXT("[%s] FaceYaw_Cached : %f"), *ITTSTRING_CLASS_FUNC, FaceYaw_Cached);
		ITTLOG(Warning, TEXT("[%s] FaceYaw : %f"), *ITTSTRING_CLASS_FUNC, FaceYaw);
		
		FaceYaw_Cached = FaceYaw;
	}
}
// ==================================== //