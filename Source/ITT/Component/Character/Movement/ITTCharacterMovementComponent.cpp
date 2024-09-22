// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTCharacterMovementComponent.h"

#include "Character/ITTCharacterFunctionLibrary.h"

#include "Character/ITTCharacterBase.h"
#include "Component/Character/Stat/ITTCharacterStatComponent.h"

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

	// Bind OnChange delegate
	MovementModeMachine->OnChangeStateDelegate = FITTOnChangeStateDelegate::CreateUObject(this, &UITTCharacterMovementComponent::OnChangeMovementMode);
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


// -- OnChange -- //
void UITTCharacterMovementComponent::OnChangeMovementMode(int64 PreviousMovementModeId, int64 CurrentMovementModeId)
{
	int32 DataIndex = -1;
	
	FITTMovementMode PreviousMovementMode(static_cast<uint32>(PreviousMovementModeId));
	FITTMovementMode CurrentMovementMode(static_cast<uint32>(CurrentMovementModeId));

	// Previous Movement Mode
	if (IsSprintMode(PreviousMovementMode, DataIndex))
	{
		OnStopSprint(DataIndex);
	}
	
	// Current Movement Mode
	if (IsSprintMode(CurrentMovementMode, DataIndex))
	{
		OnStartSprint(DataIndex);
	}
}
// =========================================== //


// ========== Movement ========== //
// -- Sprint -- //
void UITTCharacterMovementComponent::StartSprint()
{
	FITTMovementMode SprintMode;
	if (CanSprint(SprintMode))
	{
		SetITTMovementMode(SprintMode);
	}
}

void UITTCharacterMovementComponent::StopSprint()
{
	FITTMovementMode NoneSprintMode;
	if (IsSprint(NoneSprintMode))
	{
		SetITTMovementMode(NoneSprintMode);
	}
}

bool UITTCharacterMovementComponent::CanSprint(FITTMovementMode& OutSprintMode) const
{
	int32 DataIndex = -1;
	
	FITTMovementMode CurrentMovementMode(static_cast<uint32>(MovementModeMachine->GetCurrentStateId()));

	if (IsNoneSprintMode(CurrentMovementMode, DataIndex))
	{
		OutSprintMode = SprintModeDatas[DataIndex].SprintMode;
		return true;
	}

	return false;
}

bool UITTCharacterMovementComponent::IsSprint(FITTMovementMode& OutNoneSprintMode) const
{
	int32 DataIndex = -1;
	
	FITTMovementMode CurrentMovementMode(static_cast<uint32>(MovementModeMachine->GetCurrentStateId()));

	if (IsSprintMode(CurrentMovementMode, DataIndex))
	{
		OutNoneSprintMode = SprintModeDatas[DataIndex].NoneSprintMode;
		return true;
	}

	return false;
}

bool UITTCharacterMovementComponent::IsNoneSprintMode(const FITTMovementMode& InMovementMode, int32& OutDataIndex) const
{
	for (int32 i = 0; i < SprintModeDatas.Num(); ++i)
	{
		if (SprintModeDatas[i].NoneSprintMode == InMovementMode)
		{
			OutDataIndex = i;
			return true;
		}
	}

	OutDataIndex = -1;
	return false;
}

bool UITTCharacterMovementComponent::IsSprintMode(const FITTMovementMode& InMovementMode, int32& OutDataIndex) const
{
	for (int32 i = 0; i < SprintModeDatas.Num(); ++i)
	{
		if (SprintModeDatas[i].SprintMode == InMovementMode)
		{
			OutDataIndex = i;
			return true;
		}
	}

	OutDataIndex = -1;
	return false;
}

void UITTCharacterMovementComponent::OnStartSprint(int32 DataIndex)
{
	if (AITTCharacterBase* CharacterBase = Cast<AITTCharacterBase>(GetOwner()))
	{
		if (UITTCharacterStatComponent* CharacterStatComponent = CharacterBase->GetCharacterStatComponent())
		{
			EITTCharacterStat SprintSpeedStat = SprintModeDatas[DataIndex].SprintSpeedStat;
			MaxWalkSpeed = CharacterStatComponent->GetCharacterStat(SprintSpeedStat);
		}
	}
}

void UITTCharacterMovementComponent::OnStopSprint(int32 DataIndex)
{
	if (AITTCharacterBase* CharacterBase = Cast<AITTCharacterBase>(GetOwner()))
	{
		if (UITTCharacterStatComponent* CharacterStatComponent = CharacterBase->GetCharacterStatComponent())
		{
			EITTCharacterStat SprintSpeedStat = SprintModeDatas[DataIndex].NoneSprintSpeedStat;
			MaxWalkSpeed = CharacterStatComponent->GetCharacterStat(SprintSpeedStat);
		}
	}
}
// ============================== //
