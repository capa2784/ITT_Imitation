// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ITTStateMachine.generated.h"

/**
 * 
 */
DECLARE_DELEGATE_TwoParams(FITTOnChangeStateDelegate, int64, int64);


UCLASS()
class ITT_API UITTStateMachine : public UObject
{
	GENERATED_BODY()

public:
	UITTStateMachine();

	
	void BuiltInInitialize(const FName& _StateMachineName);

	
	// ========== Change ========== //
	void SetNextState(uint32 Id, bool bChangeImmediately = true);
	int64 ChangeToNextState();
	
	void ResetState();
	
private:
	void SetState_Internal(uint32 Id);
	// ============================ //
	
	
public:
	// ==================== Getter ==================== //
	// ========== State Machine ========== //
	const FName& GetStateMachineName() const { return StateMachineName; }
	// =================================== //


	// ========== State ========== //
	int64 GetPreviousStateId() const { return PreviousStateId; }
	
	int64 GetCurrentStateId() const { return CurrentStateId; }
	
	int64 GetNextStateId() const { return NextStateId; }

	bool IsStateDirty() const;
	// =========================== //
	// ================================================ //
	
	
private:
	// ========== State Machine ========== //
	FName StateMachineName;
	// =================================== //

	
	// ========== State ========== //
	int64 PreviousStateId;
	int64 CurrentStateId;
	int64 NextStateId;
	// =========================== //
	
	
public:
	// ==================== Delegate ==================== //
	// ========== Change ========== //
	FITTOnChangeStateDelegate OnChangeStateDelegate;
	// ============================ //
	// ================================================== //
};
