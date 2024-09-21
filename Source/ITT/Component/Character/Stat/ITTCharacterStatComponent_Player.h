// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTCharacterStatComponent.h"
#include "ITTCharacterStatComponent_Player.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=ITTComponent, meta=(BlueprintSpawnableComponent))
class ITT_API UITTCharacterStatComponent_Player : public UITTCharacterStatComponent
{
	GENERATED_BODY()

public:
	UITTCharacterStatComponent_Player();

	
	virtual void InitializeComponent() override;
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	
	// ========== Stat Data ========== //
	virtual const FITTCharacterStat* GetCharacterStats() const override { return &CharacterStats_Player; }
	
private:
	bool InitializeCharacterStatBase();
	// =============================== //
	
	
protected:
	// ========== Stat Data ========== //
	UPROPERTY()
	FITTCharacterStat_Player CharacterStatBase_Player;

	UPROPERTY()
	FITTCharacterStat_Player CharacterStats_Player;
	// =============================== //
};


// ToDo : Update / Modify CharacterStats