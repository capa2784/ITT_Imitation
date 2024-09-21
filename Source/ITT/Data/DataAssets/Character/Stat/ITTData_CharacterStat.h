// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Character/ITTDefine_Character.h"
#include "ITTData_CharacterStat.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ITT_API UITTData_CharacterStat : public UDataAsset
{
	GENERATED_BODY()

public:
	// ==================== Getter ==================== //
	// ========== Stat Data ========== //
	virtual const FITTCharacterStat* GetCharacterStats() const { return nullptr; }

	template<typename T>
	const T* GetCharacterStats() const
	{
		if (!GetCharacterStats())
		{
			ITTLOG(Error, TEXT("[%s] CharacterStatData is nullptr"), *ITTSTRING_CLASS_FUNC);
			return nullptr;
		}

		if (const T* Ret = Cast<T>(GetCharacterStats()))
		{
			return Ret;
		}

		ITTENSUREF(false, TEXT("[%s] Cast to wrong type"), *ITTSTRING_CLASS_FUNC);
		return nullptr;
	}
	// =============================== //
	// ================================================ //
};
