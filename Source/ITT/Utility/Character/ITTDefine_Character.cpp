// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTDefine_Character.h"

#include "ITTUtilityFunctionLibrary.h"


// ==================== Struct ==================== //
// ========== Movement Mode ========== //
// -- FITTMovementMode -- //
bool FITTMovementMode::operator==(const FITTMovementMode& Other) const
{
	return GetFullMode() == Other.GetFullMode();
}

bool FITTMovementMode::operator!=(const FITTMovementMode& Other) const
{
	return GetFullMode() != Other.GetFullMode();
}

bool FITTMovementMode::operator<(const FITTMovementMode& Other) const
{
	return GetFullMode() < Other.GetFullMode();
}

bool FITTMovementMode::operator>(const FITTMovementMode& Other) const
{
	return GetFullMode() > Other.GetFullMode();
}

bool FITTMovementMode::operator<=(const FITTMovementMode& Other) const
{
	return GetFullMode() <= Other.GetFullMode();
}

bool FITTMovementMode::operator>=(const FITTMovementMode& Other) const
{
	return GetFullMode() >= Other.GetFullMode();
}


uint32 FITTMovementMode::GetFullMode() const
{
	return MainMode << 24 | SubMode << 16 | AdditiveMode1 << 8 | AdditiveMode2;
}

void FITTMovementMode::SetUsingFullMode(uint32 _FullMode)
{
	uint32 FullMode_Cast = StaticCast<uint32>(_FullMode);
	
	if (FullMode_Cast < (1 << 24))
	{
		MainMode = 0;
		SubMode = 0;
		AdditiveMode1 = 0;
		AdditiveMode2 = 0;
	}
	
	MainMode = static_cast<uint8>((FullMode_Cast & 0b11111111 << 24) >> 24);
	SubMode = static_cast<uint8>((FullMode_Cast & 0b11111111 << 16) >> 16);
	AdditiveMode1 = static_cast<uint8>((FullMode_Cast & 0b11111111 << 8) >> 8);
	AdditiveMode2 = static_cast<uint8>(FullMode_Cast & 0b11111111);
}


uint32 GetTypeHash(const FITTMovementMode& MovementMode)
{
	return FCrc::MemCrc32(&MovementMode, sizeof(FITTMovementMode));
}
// =================================== //


// ========== Stat ========== //
// ----- FITTCharacterStat ----- //
float FITTCharacterStat::GetCharacterStat(EITTCharacterStat StatName) const
{
	switch (StatName)
	{
	case EITTCharacterStat::None :
		{
			ITTLOG(Error, TEXT("Get character stat 'None'"));
			return 0.f;
		}
	
	case EITTCharacterStat::MinWalkSpeed :
		{
			return MinWalkSpeed;
		}

	case EITTCharacterStat::MaxJogSpeed:
		{
			return MaxJogSpeed;
		}
		
	case EITTCharacterStat::MaxWalkSpeedPerMaxJogSpeed :
		{
			return MaxWalkSpeedPerMaxJogSpeed;
		}
		
	case EITTCharacterStat::MaxSprintSpeed :
		{
			return MaxSprintSpeed;
		}
		
	default:
		{
			FString EnumName = UITTUtilityFunctionLibrary::ConvertEnumToString(TEXT("EITTCharacterStat"), StatName);
			ITTLOG(Error, TEXT("Stat doesn't exist [StatName : %s]"), *EnumName);
			return 0.f;
		}
	}
}

void FITTCharacterStat::CopyStat(const FITTCharacterStat* Original, bool ExactClass)
{
	MinWalkSpeed = Original->MinWalkSpeed;
	MaxJogSpeed = Original->MaxJogSpeed;
	MaxWalkSpeedPerMaxJogSpeed = Original->MaxWalkSpeedPerMaxJogSpeed;
	MaxSprintSpeed = Original->MaxSprintSpeed;
}


// ----- FITTCharacterStat_Player ----- //
float FITTCharacterStat_Player::GetCharacterStat(EITTCharacterStat StatName) const
{
	switch (StatName)
	{
	case EITTCharacterStat::MaxCrouchSpeed :
		{
			return MaxCrouchSpeed;
		}
		
	default:
		{
			return FITTCharacterStat::GetCharacterStat(StatName);
		}
	}
}

void FITTCharacterStat_Player::CopyStat(const FITTCharacterStat* Original, bool ExactClass)
{
	FITTCharacterStat::CopyStat(Original);
	
	if (const FITTCharacterStat_Player* Original_Cast = static_cast<const FITTCharacterStat_Player*>(Original))
	{
		MaxCrouchSpeed = Original_Cast->MaxCrouchSpeed;
	}
	else
	{
		ITTCHECKF(ExactClass, TEXT("Cast as the wrong type"));
	}
}
// ========================== //
// ================================================ //