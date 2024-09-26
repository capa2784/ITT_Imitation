// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTTable_String.h"


UITTTable_String::UITTTable_String()
{
}


// ========== String ========== //
void UITTTable_String::GetString(FString& OutString, int32 InStringIdex, EITTLanguage InLanguage) const
{
	FITTTableRow_String* Row = GetDataTable()->FindRow<FITTTableRow_String>(FName(FString::FromInt(InStringIdex)), ITTTEXT_CLASS_FUNC);
	if (Row)
	{
		switch (InLanguage)
		{
		case EITTLanguage::En:
			OutString = Row->English;
			
		case EITTLanguage::Kr:
			OutString = Row->Korean;

		default:
			OutString = Row->English;	
		}
	}
	else
	{
		ITTLOG(Error, TEXT("[%s] Invalid String [StringIndex : %d]"), *ITTSTRING_CLASS_FUNC, InStringIdex);
		OutString = "TXT_ERROR_#" + FString::FromInt(InStringIdex);
	}
}
// ============================ //