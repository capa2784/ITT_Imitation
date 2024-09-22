// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Character/ITTDefine_Character.h"
#include "ITTCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=ITTComponent, meta=(BlueprintSpawnableComponent))
class ITT_API UITTCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UITTCharacterMovementComponent();

	
	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	
	// ========== Movement Mode Machine ========== //
	void CreateMovementModeMachine();

	void DestroyMovementModeMachine();
	
	virtual void SetMovementMode(EMovementMode NewMovementMode, uint8 NewCustomMode = 0) override;

	virtual void SetITTMovementMode(FITTMovementMode ITTMovementMode, bool bChangeImmediately = true);
	
	virtual void SetITTMovementMode(uint8 MainMode,  uint8 SubMode = 0, uint8 AdditiveMode1 = 0, uint8 AdditiveMode2 = 0, bool bChangeImmediately = true);

	template<typename T>
	void SetITTMovementMode(EMovementMode MainMode,  T SubMode, uint8 AdditiveMode1 = 0, uint8 AdditiveMode2 = 0, bool bChangeImmediately = true)
	{
		SetITTMovementMode(static_cast<uint8>(MainMode), SubMode, AdditiveMode1, AdditiveMode2, bChangeImmediately);
	}

	
	// -- OnChange -- //
	UFUNCTION()
	virtual void OnChangeMovementMode(int64 PreviousMovementModeId, int64 CurrentMovementModeId);
	// =========================================== //

	
	// ========== Movement ========== //
	// -- Sprint -- //
	virtual void StartSprint();

	virtual void StopSprint();
	
	virtual bool CanSprint(FITTMovementMode& OutSprintMode) const;

	virtual bool IsSprint(FITTMovementMode& OutNoneSprintMode) const;

	virtual bool IsNoneSprintMode(const FITTMovementMode& InMovementMode, int32& OutDataIndex) const;
	
	virtual bool IsSprintMode(const FITTMovementMode& InMovementMode, int32& OutDataIndex) const;
	
	virtual void OnStartSprint(int32 DataIndex);

	virtual void OnStopSprint(int32 DataIndex);
	// ============================== //

	
	// ==================== Getter ==================== //
	// ========== Movement Mode Machine ========== //
	class UITTStateMachine* GetMovementModeMachine() { return MovementModeMachine; }
	// =========================================== //
	// ================================================ //

	
protected:
	// ========== Movement Mode Machine ========== //
	TObjectPtr<class UITTStateMachine> MovementModeMachine;
	// =========================================== //

	
	// ========== Movement ========== //
	// -- Sprint -- //
	UPROPERTY(Category=ITT, EditAnywhere)
	TArray<FITTSprintModeData> SprintModeDatas;
	// ============================== //
};