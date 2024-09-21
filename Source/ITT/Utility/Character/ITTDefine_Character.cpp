// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTDefine_Character.h"


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
// ================================================ //