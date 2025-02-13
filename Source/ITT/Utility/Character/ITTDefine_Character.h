﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTDefine_Character.generated.h"


// ==================== Enum ==================== //
// ========== Player ========== //
UENUM(BlueprintType)
enum class EITTCharacter_Player : uint8
{
	Cody,
	May
};
// ============================ //


// ========== Movement Mode ========== //
// -- Sub Movement Mode -- //
// naming "MainMode_SubMode"
UENUM(BlueprintType)
enum class EITTSubMovementMode_Walking : uint8
{
	Walking_Jogging,
	Walking_Walking,
	Walking_Sprint,
	Walking_Dash,
	Walking_Crouch,

	EITTSubMovementMode_Walking_Max
};

UENUM(BlueprintType)
enum class EITTSubMovementMode_NavWalking : uint8
{
	NavWalking_NavWalking,

	EITTSubMovementMode_NavWalking_Max
};

UENUM(BlueprintType)
enum class EITTSubMovementMode_Falling : uint8
{
	Falling_Falling,
	Falling_Jump,
	Falling_DoubleJump,
	Falling_LongJump,

	EITTSubMovementMode_Falling_Max
};

UENUM(BlueprintType)
enum class EITTSubMovementMode_Swimming : uint8
{
	Swimming_Swimming,

	EITTSubMovementMode_Swimming_Max
};

UENUM(BlueprintType)
enum class EITTSubMovementMode_Flying : uint8
{
	Flying_Flying,

	EITTSubMovementMode_Flying_Max
};

UENUM(BlueprintType)
enum class EITTSubMovementMode_Custom : uint8
{
	EITTSubMovementMode_Custom_Max
};
// =================================== //


// ========== Stat ========== //
UENUM(BlueprintType)
enum class EITTCharacterStat : uint8
{
	None,

	MinWalkSpeed,
	MaxJogSpeed,
	MaxWalkSpeedPerMaxJogSpeed,
	MaxSprintSpeed,
	MaxCrouchSpeed,
	
	EITTCharacterStat_Max
};
// ========================== //
// ============================================== //


// ==================== Struct ==================== //
// ========== Movement Mode ========== //
USTRUCT(Blueprintable)
struct FITTMovementMode
{
	GENERATED_BODY()

	FITTMovementMode()
		: MainMode(0), SubMode(0), AdditiveMode1(0), AdditiveMode2(0)
	{
	}

	FITTMovementMode(uint8 _MainMode, uint8 _SubMode)
		: MainMode(_MainMode), SubMode(_SubMode), AdditiveMode1(0), AdditiveMode2(0)
	{
	}

	FITTMovementMode(uint8 _MainMode, uint8 _SubMode, uint8 _AdditiveMode1, uint8 _AdditiveMode2)
		: MainMode(_MainMode), SubMode(_SubMode), AdditiveMode1(_AdditiveMode1), AdditiveMode2(_AdditiveMode2)
	{
	}

	FITTMovementMode(uint32 _FullMode)
	{
		SetUsingFullMode(_FullMode);
	}

	
	bool operator==(const FITTMovementMode& Other) const;
	bool operator!=(const FITTMovementMode& Other) const;
	bool operator<(const FITTMovementMode& Other) const;
	bool operator>(const FITTMovementMode& Other) const;
	bool operator<=(const FITTMovementMode& Other) const;
	bool operator>=(const FITTMovementMode& Other) const;

	
	uint32 GetFullMode() const;
	void SetUsingFullMode(uint32 _FullMode);

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 MainMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 SubMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 AdditiveMode1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 AdditiveMode2;
};

uint32 GetTypeHash(const FITTMovementMode& MovementMode);
// =================================== //

// ========== Movement Mode Data ========== //
USTRUCT(Blueprintable)
struct FITTSprintModeData
{
	GENERATED_BODY()
	
	FITTSprintModeData()
	{
	}
	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTMovementMode NoneSprintMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EITTCharacterStat NoneSprintSpeedStat;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FITTMovementMode SprintMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EITTCharacterStat SprintSpeedStat;
};
// ======================================== //

// ========== Stat ========== //
USTRUCT(Blueprintable)
struct FITTCharacterStat
{
	GENERATED_BODY()

	FITTCharacterStat()
		: MinWalkSpeed(0.03f), MaxJogSpeed(500.f), MaxWalkSpeedPerMaxJogSpeed(0.4f), MaxSprintSpeed(1000.f)
	{
	}

	virtual ~FITTCharacterStat() {}


	virtual float GetCharacterStat(EITTCharacterStat StatName) const;

	virtual void CopyStat(const FITTCharacterStat* Original, bool ExactClass = true);


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MinWalkSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxJogSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxWalkSpeedPerMaxJogSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxSprintSpeed;
};

USTRUCT(Blueprintable)
struct FITTCharacterStat_Player : public FITTCharacterStat
{
	GENERATED_BODY()

	FITTCharacterStat_Player()
		: MaxCrouchSpeed(200.f)
	{
	}

	virtual ~FITTCharacterStat_Player() override {}

	
	virtual float GetCharacterStat(EITTCharacterStat StatName) const override;

	virtual void CopyStat(const FITTCharacterStat* Original, bool ExactClass = true) override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxCrouchSpeed;
};
// ========================== //
// ================================================ //