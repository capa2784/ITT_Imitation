// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTCharacterMovementComponent.h"

#include "Character/ITTCharacterFunctionLibrary.h"

#include "Character/ITTCharacterBase.h"

#include "StateMachine/ITTStateMachine.h"


UITTCharacterMovementComponent::UITTCharacterMovementComponent()
{
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
	
	// Configure character movement
	bOrientRotationToMovement = true;
	RotationRate = FRotator(0.0f, 500.0f, 0.0f);
}


void UITTCharacterMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();

	CreateMovementModeMachine();
}

void UITTCharacterMovementComponent::UninitializeComponent()
{
	DestroyMovementModeMachine();
	
	Super::UninitializeComponent();
}

void UITTCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UITTCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


// ========== Movement Mode Machine ========== //
void UITTCharacterMovementComponent::CreateMovementModeMachine()
{
	if (MovementModeMachine)
	{
		return;
	}
	
	MovementModeMachine = ITTNewObject<UITTStateMachine>(UITTStateMachine::StaticClass());
	MovementModeMachine->AddToRoot();
}

void UITTCharacterMovementComponent::DestroyMovementModeMachine()
{
	if (IsValid(MovementModeMachine))
	{
		MovementModeMachine->RemoveFromRoot();
		ITTDeleteObject(MovementModeMachine);
	}
}

void UITTCharacterMovementComponent::SetMovementMode(EMovementMode NewMovementMode, uint8 NewCustomMode)
{
	if (MovementModeMachine)
	{
		uint8 MainMode = static_cast<uint8>(NewMovementMode);
		uint8 SubMode = NewCustomMode;

		if (UITTCharacterFunctionLibrary::CheckMovementModeValid(FITTMovementMode(MainMode, SubMode)))
		{
			FITTMovementMode CurrentMovementMode(static_cast<uint32>(MovementModeMachine->GetCurrentStateId()));
		
			if (CurrentMovementMode.MainMode != MainMode)
			{
				MovementModeMachine->SetNextState(FITTMovementMode(MainMode, SubMode).GetFullMode());
			}
		}
	}
	
	Super::SetMovementMode(NewMovementMode, NewCustomMode);
}

void UITTCharacterMovementComponent::SetITTMovementMode(FITTMovementMode ITTMovementMode, bool bChangeImmediately)
{
	if (MovementModeMachine)
	{
		if (UITTCharacterFunctionLibrary::CheckMovementModeValid(ITTMovementMode))
		{
			MovementModeMachine->SetNextState(ITTMovementMode.GetFullMode(), bChangeImmediately);
		
			FITTMovementMode CurrentMovementMode(static_cast<uint32>(MovementModeMachine->GetCurrentStateId()));
		
			if (CurrentMovementMode.MainMode != ITTMovementMode.MainMode)
			{
				Super::SetMovementMode(static_cast<EMovementMode>(ITTMovementMode.MainMode), ITTMovementMode.SubMode);
			}
		}
	}
}

void UITTCharacterMovementComponent::SetITTMovementMode(uint8 MainMode, uint8 SubMode,
	uint8 AdditiveMode1, uint8 AdditiveMode2, bool bChangeImmediately)
{
	if (MovementModeMachine)
	{
		SetITTMovementMode(FITTMovementMode(MainMode, SubMode, AdditiveMode1, AdditiveMode2), bChangeImmediately);
	}
}
// =========================================== //