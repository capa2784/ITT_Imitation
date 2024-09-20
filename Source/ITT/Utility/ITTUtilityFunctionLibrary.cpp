// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTUtilityFunctionLibrary.h"


// ========== Convert Enum ========== //
FString UITTUtilityFunctionLibrary::ConvertEnumToString(const FString& EnumName, int64 EnumValue)
{
	UEnum* Enum = FindObject<UEnum>(nullptr, *EnumName);
	return Enum ? Enum->GetNameStringByValue(EnumValue) : FString();
}

FName UITTUtilityFunctionLibrary::ConvertEnumToName(const FString& EnumName, int64 EnumValue)
{
	UEnum* Enum = FindObject<UEnum>(nullptr, *EnumName);
	return Enum ? Enum->GetNameByValue(EnumValue) : FName();
}
// ================================== //