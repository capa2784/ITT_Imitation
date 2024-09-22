// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTAnimationHelperComponent.h"

#include "Data/DataAssets/Animation/SubAnimation/ITTData_SubAnim.h"


UITTAnimationHelperComponent::UITTAnimationHelperComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UITTAnimationHelperComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UITTAnimationHelperComponent::TickComponent(float DeltaTime, ELevelTick TickType,
												 FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


// ========== Anim Data ========== //
UITTData_SubAnim* UITTAnimationHelperComponent::GetSubAnimData(const FITTMovementMode& MovementMode) const
{
	if (SubAnimDatas.Contains(MovementMode))
	{
		return *SubAnimDatas.Find(MovementMode);
	}

	ITTLOG(Error, TEXT("[%s] SubAnimData don't exist [MovementMode : Main - %d, Sub - %d, Additive1 - %d, Additive2 - %d]"), *ITTSTRING_CLASS_FUNC, MovementMode.MainMode, MovementMode.SubMode, MovementMode.AdditiveMode1, MovementMode.AdditiveMode2);
	return nullptr;
}

TSubclassOf<UAnimInstance> UITTAnimationHelperComponent::GetSubAnimInstanceClass(const FITTMovementMode& MovementMode) const
{
	if (UITTData_SubAnim* Data = GetSubAnimData(MovementMode))
	{
		return Data->SubAnimInstanceClass;
	}

	return nullptr;
}
// =============================== //
