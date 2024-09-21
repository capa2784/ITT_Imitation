// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTCharacterStatComponent_Player.h"

#include "Data/DataAssets/Character/Stat/ITTData_CharacterStat_Player.h"


UITTCharacterStatComponent_Player::UITTCharacterStatComponent_Player()
{
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
}


void UITTCharacterStatComponent_Player::InitializeComponent()
{
	Super::InitializeComponent();

	InitializeCharacterStatBase();
}

void UITTCharacterStatComponent_Player::BeginPlay()
{
	Super::BeginPlay();
}

void UITTCharacterStatComponent_Player::TickComponent(float DeltaTime, ELevelTick TickType,
													  FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


// ========== Stat Data ========== //
bool UITTCharacterStatComponent_Player::InitializeCharacterStatBase()
{
	if (!CharacterStatData)
	{
		ITTLOG(Error, TEXT("[%s] CharacterStatData is nullptr"), *ITTSTRING_CLASS_FUNC);
		return false;
	}

	if (const UITTData_CharacterStat_Player* PlayerStatData = Cast<UITTData_CharacterStat_Player>(GetCharacterStatData()))
	{
		CharacterStatBase_Player.CopyStat(PlayerStatData->GetCharacterStats());
		CharacterStats_Player = CharacterStatBase_Player;

		return true;
	}
	
	ITTLOG(Error, TEXT("[%s] CharacterStatData can't cast to FITTCharacterStat_Player"), *ITTSTRING_CLASS_FUNC);
	return false;
}
// =============================== //