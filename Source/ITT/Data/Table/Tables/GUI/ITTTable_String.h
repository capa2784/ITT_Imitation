// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Data/Table/ITTTableBase.h"
#include "GUI/ITTDefine_GUI.h"
#include "ITTTable_String.generated.h"

/**
 * 
 */
USTRUCT()
struct FITTTableRow_String : public FTableRowBase
{
	GENERATED_BODY()

	FITTTableRow_String()
	{
	}

	UPROPERTY(EditAnywhere)
	FString English;
	
	UPROPERTY(EditAnywhere)
	FString Korean;
};


UCLASS()
class ITT_API UITTTable_String : public UITTTableBase
{
	GENERATED_BODY()

public:
	static FName GetTableName() { return FName(TableName); }

	
	UITTTable_String();

	
	// ========== String ========== //
	void GetString(FString& OutString, int32 InStringIdex, EITTLanguage InLanguage) const;
	// ============================ //

	
private:
	static constexpr char TableName[] = "DT_String";
};
