// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTCharacterFunctionLibrary.h"

#include "Engine/EngineTypes.h"


// ========== Movement Mode ========== //
bool UITTCharacterFunctionLibrary::CheckMovementModeValid(const FITTMovementMode& ITTMovementMode)
{
	// ToDo : Check AdditiveMode Valid

	if (ITTMovementMode.MainMode == static_cast<uint8>(EMovementMode::MOVE_None))
	{
		ITTLOG(Warning, TEXT("[%s] MainMovementMode is none"), *ITTSTRING_CLASS_FUNC);
		return false;
	}
	
	if (ITTMovementMode.MainMode >= static_cast<uint8>(EMovementMode::MOVE_MAX))
	{
		ITTENSUREF(false, TEXT("[%s] MainMovementMode is not valid [MainMode : %d]"), *ITTSTRING_CLASS_FUNC, ITTMovementMode.MainMode);
		return false;
	}
	
	bool bIsValidSubMode = true;
	
	switch (static_cast<EMovementMode>(ITTMovementMode.MainMode))
	{
	case EMovementMode::MOVE_Walking:
		{
			if (ITTMovementMode.SubMode >= static_cast<uint8>(EITTSubMovementMode_Walking::EITTSubMovementMode_Walking_Max))
			{
				bIsValidSubMode = false;
			}
			break;
		}

	case EMovementMode::MOVE_NavWalking:
		{
			if (ITTMovementMode.SubMode >= static_cast<uint8>(EITTSubMovementMode_NavWalking::EITTSubMovementMode_NavWalking_Max))
			{
				bIsValidSubMode = false;
			}
			break;
		}

	case EMovementMode::MOVE_Falling:
		{
			if (ITTMovementMode.SubMode >= static_cast<uint8>(EITTSubMovementMode_Falling::EITTSubMovementMode_Falling_Max))
			{
				bIsValidSubMode = false;
			}
			break;
		}

	case EMovementMode::MOVE_Swimming:
		{
			if (ITTMovementMode.SubMode >= static_cast<uint8>(EITTSubMovementMode_Swimming::EITTSubMovementMode_Swimming_Max))
			{
				bIsValidSubMode = false;
			}
			break;
		}

	case EMovementMode::MOVE_Flying:
		{
			if (ITTMovementMode.SubMode >= static_cast<uint8>(EITTSubMovementMode_Flying::EITTSubMovementMode_Flying_Max))
			{
				bIsValidSubMode = false;
			}
			break;
		}

	case EMovementMode::MOVE_Custom:
		{
			if (ITTMovementMode.SubMode >= static_cast<uint8>(EITTSubMovementMode_Custom::EITTSubMovementMode_Custom_Max))
			{
				bIsValidSubMode = false;
			}
			break;
		}

	default:
		break;
	}

	if (!bIsValidSubMode)
	{
		ITTENSUREF(false, TEXT("[%s] SubMovementMode is not valid [MainMode : %d, SubMode : %d]"), *ITTSTRING_CLASS_FUNC, ITTMovementMode.MainMode, ITTMovementMode.SubMode);
	}

	return bIsValidSubMode;
}
// =================================== //