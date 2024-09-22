// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Table/ITTTableBase.h"
#include "Engine/DataTable.h"
#include "ITTTable_Level.generated.h"

/**
 * 
 */
USTRUCT()
struct FITTTableRow_Level : public FTableRowBase
{
	GENERATED_BODY()

	FITTTableRow_Level()
		: LevelPath(FName()), SoftObject(nullptr)
	{
	}

	UPROPERTY(EditAnywhere)
	FName LevelPath;
	
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> SoftObject;
};


UCLASS()
class ITT_API UITTTable_Level : public UITTTableBase
{
	GENERATED_BODY()

public:
	static FName GetTableName() { return FName(TableName); }

	
	UITTTable_Level();

	
	// ========== Level ========== //
	const FName& GetLevelPath(const FName& LevelName) const;
	const TSoftObjectPtr<UWorld>& GetSoftObject(const FName& LevelName) const;
	// =========================== //
	
	
private:
	static constexpr char TableName[] = "DT_Level";
};
