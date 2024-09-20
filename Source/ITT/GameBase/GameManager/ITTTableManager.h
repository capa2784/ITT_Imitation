// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ITTSingleton.h"
#include "Engine/DataTable.h"
#include "Templates/SubclassOf.h"
#include "ITTTableManager.generated.h"

/**
 * 
 */
USTRUCT()
struct FITTTableRow_TableList : public FTableRowBase
{
	GENERATED_BODY()

	FITTTableRow_TableList()
		: DataTable(nullptr), ITTTableClass(nullptr)
	{
	}
	
	UPROPERTY(EditAnywhere)
	UDataTable* DataTable;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UITTTableBase> ITTTableClass;
};


UCLASS()
class ITT_API UITTTableManager : public UObject, public TITTSingleton<UITTTableManager>
{
	GENERATED_BODY()

public:
	UITTTableManager();

	
	virtual void BuiltInInitialize() override;
	virtual void Initialize() override;
	virtual void BuiltInFinalize() override;

	
private:
	// ========== Tables ========== //
	void CreateITTTables();
	void DestroyITTTables();
	
	
public:
	template<class T>
	TObjectPtr<T> GetITTTable(const FName& TableName)
	{
		if (!IsValid(TableList))
		{
			ITTCHECKF(false, TEXT("[%s] TableList isn't vaild [TableName : %s]"), *ITTSTRING_CLASS_FUNC, *TableName.ToString());
			return nullptr;
		}

		if (!bBuiltInInitialized || !bInitialized)
		{
			ITTCHECKF(false, TEXT("[%s] Not initialized [TableName : %s]"), *ITTSTRING_CLASS_FUNC, *TableName.ToString());
			return nullptr;
		}
		
		if (TableName.IsNone())
		{
			ITTCHECKF(false, TEXT("[%s] TableName is empty [TableName : %s]"), *ITTSTRING_CLASS_FUNC, *TableName.ToString());
			return nullptr;
		}

		if (!ITTTables.Contains(TableName))
		{
			ITTCHECKF(false, TEXT("[%s] Couldn't find ITTTable [TableName : %s]"), *ITTSTRING_CLASS_FUNC, *TableName.ToString());
			return nullptr;
		}
		
		UITTTableBase* ITTTable = *ITTTables.Find(TableName);
		return Cast<T>(ITTTable);
	}
	
	UDataTable* GetDataTable(const FName& TableName);
	// ============================ //
	
	
private:
	bool bBuiltInInitialized;
	bool bInitialized;

	
	// ========== Table List ========== //
	UPROPERTY()
	UDataTable* TableList;
	// ================================ //
	
	
	// ========== Tables ========== //
	UPROPERTY()
	TMap<FName, TObjectPtr<class UITTTableBase>> ITTTables;
	// ============================ //

	
#define TableMgr UITTTableManager::GetInstance()
};
