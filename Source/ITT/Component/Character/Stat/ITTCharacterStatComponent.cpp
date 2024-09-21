// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTCharacterStatComponent.h"

#include "Data/DataAssets/Character/Stat/ITTData_CharacterStat.h"


UITTCharacterStatComponent::UITTCharacterStatComponent()
{
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
}


void UITTCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

void UITTCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UITTCharacterStatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
											   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


// ========== Stat Data ========== //
const FITTCharacterStat* UITTCharacterStatComponent::GetCharacterStats() const
{
	if (CharacterStatData)
	{
		return CharacterStatData->GetCharacterStats();
	}

	ITTLOG(Error, TEXT("[%s] CharacterStatData is nullptr"), *ITTSTRING_CLASS_FUNC);
	return nullptr;
}

float UITTCharacterStatComponent::GetCharacterStat(const EITTCharacterStat StatName) const
{
	if (const FITTCharacterStat* Stats = GetCharacterStats())
	{
		return Stats->GetCharacterStat(StatName);
	}

	return 0.f;
}
// =============================== //