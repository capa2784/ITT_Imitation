// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTData_CharacterStat.h"
#include "Character/ITTDefine_Character.h"
#include "ITTData_CharacterStat_Player.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTData_CharacterStat_Player : public UITTData_CharacterStat
{
	GENERATED_BODY()

public:
	// ==================== Getter ==================== //
	// ========== Stat Data ========== //
	virtual const FITTCharacterStat* GetCharacterStats() const override { return &CharacterStats_Player; }
	// =============================== //
	// ================================================ //

	
protected:
	// ========== Stat Data ========== //
	UPROPERTY(EditAnywhere)
	FITTCharacterStat_Player CharacterStats_Player;
	// =============================== //
};
