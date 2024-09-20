// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTStateMachine.h"


UITTStateMachine::UITTStateMachine()
	: PreviousStateId(-1), CurrentStateId(-1), NextStateId(-1)
{
}


void UITTStateMachine::BuiltInInitialize(const FName& _StateMachineName)
{
	StateMachineName = _StateMachineName;
}


// ========== Change ========== //
void UITTStateMachine::SetNextState(uint32 Id, bool bChangeImmediately)
{
	NextStateId = Id;

	if (bChangeImmediately)
	{
		ChangeToNextState();
	}
}

int64 UITTStateMachine::ChangeToNextState()
{
	if (NextStateId >= 0)
	{
		SetState_Internal(NextStateId);
	}

	return NextStateId;
}

void UITTStateMachine::ResetState()
{
	PreviousStateId = -1;
	CurrentStateId = -1;
	NextStateId = -1;
}

void UITTStateMachine::SetState_Internal(uint32 Id)
{
	if (Id != CurrentStateId)
	{
		PreviousStateId = CurrentStateId;
		CurrentStateId = Id;
	}
	
	bool bDelegateBound = OnChangeStateDelegate.ExecuteIfBound(PreviousStateId, CurrentStateId);
	if (!bDelegateBound)
	{
		ITTLOG(Log, TEXT("[%s] OnChangeStateDelegate isn't bound [StateMachineName : %s]")
			, *ITTSTRING_CLASS_FUNC, *StateMachineName.ToString());
	}
}
// ============================ //


// ==================== Getter ==================== //
// ========== State ========== //
bool UITTStateMachine::IsStateDirty() const
{
	return NextStateId >= 0 && CurrentStateId != NextStateId;
}
// =========================== //
// ================================================ //