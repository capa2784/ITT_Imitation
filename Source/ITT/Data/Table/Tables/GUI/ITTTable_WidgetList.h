// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Data/Table/ITTTableBase.h"
#include "Templates/SubclassOf.h"
#include "ITTTable_WidgetList.generated.h"

/**
 * 
 */
USTRUCT()
struct FITTTableRow_WidgetList : public FTableRowBase
{
	GENERATED_BODY()

	FITTTableRow_WidgetList()
		: ITTWidgetClass(nullptr), ZOrder(0)
	{
	}

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UITTWidget> ITTWidgetClass;

	UPROPERTY(EditAnywhere)
	int32 ZOrder;
};


UCLASS()
class ITT_API UITTTable_WidgetList : public UITTTableBase
{
	GENERATED_BODY()

public:
	static FName GetTableName() { return FName(TableName); }

	
	UITTTable_WidgetList();

	
	// ========== Widget ========== //
	void GetWidgetClass(const FName& WidgetName, TSubclassOf<UITTWidget>& OutClass) const;

	int32 GetZOrder(const FName& WidgetName) const;
	// ============================ //

	
private:
	static constexpr char TableName[] = "DT_WidgetList";
};
