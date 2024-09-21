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
	// =========================================== //
	
	
	// ==================== Getter ==================== //
	// ========== Movement Mode Machine ========== //
	class UITTStateMachine* GetMovementModeMachine() { return MovementModeMachine; }
	// =========================================== //
	// ================================================ //

	
protected:
	// ========== Movement Mode Machine ========== //
	TObjectPtr<class UITTStateMachine> MovementModeMachine;
	// =========================================== //
};