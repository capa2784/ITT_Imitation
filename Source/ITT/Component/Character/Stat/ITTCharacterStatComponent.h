// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Character/ITTDefine_Character.h"
#include "ITTCharacterStatComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=ITTComponent, meta=(BlueprintSpawnableComponent))
class ITT_API UITTCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UITTCharacterStatComponent();

	
	virtual void InitializeComponent() override;
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	
	// ========== Stat Data ========== //
	virtual const FITTCharacterStat* GetCharacterStats() const;

	template<typename T>
	const T* GetCharacterStats() const
	{
		return Cast<T>(GetCharacterStats());
	}

	float GetCharacterStat(const EITTCharacterStat StatName) const;
	// =============================== //
	
	
	// ==================== Getter ==================== //
	// ========== Stat Data ========== //
	class UITTData_CharacterStat* GetCharacterStatData() const { return CharacterStatData; }
	// =============================== //
	// ================================================ //

	
protected:
	// ========== Stat Data ========== //
	UPROPERTY(Category = ITT, EditAnywhere)
	class UITTData_CharacterStat* CharacterStatData;
	// =============================== //
};