// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTTableManager.h"

#include "GameBase/BasicUtility/ITTBasicUtility.h"

#include "Data/Table/ITTTableBase.h"


UITTTableManager::UITTTableManager()
	: bBuiltInInitialized(false), bInitialized(false), TableList(nullptr)
{
}


void UITTTableManager::BuiltInInitialize()
{
	if (!bBuiltInInitialized)
	{
		const FString& TableListPath = UITTBasicUtility::GetTableListPath();
		
		TableList = LoadObject<UDataTable>(nullptr, *TableListPath);
		ITTCHECK(IsValid(TableList));

		CreateITTTables();
		
		bBuiltInInitialized = true;
	}
}

void UITTTableManager::Initialize()
{
	if (!bInitialized)
	{
		for (auto& Iter : ITTTables)
		{
			Iter.Value->Initialize();
		}

		bInitialized = true;
	}
}

void UITTTableManager::BuiltInFinalize()
{
	if (bBuiltInInitialized)
	{
		DestroyITTTables();
	}

	TableList = nullptr;
	
	bInitialized = false;
	bBuiltInInitialized = false;
}


// ========== Tables ========== //
void UITTTableManager::CreateITTTables()
{
	ITTTables.Empty();
	
	const TArray<FName>& RowNames = TableList->GetRowNames();

	for (const FName& RowName : RowNames)
	{
		FITTTableRow_TableList* Row = TableList->FindRow<FITTTableRow_TableList>(RowName, ITTTEXT_CLASS_FUNC);
		if (Row)
		{
			ITTCHECK(Row->ITTTableClass);
			ITTCHECK(Row->DataTable);
			
			TObjectPtr<UITTTableBase> ITTTable = ITTNewObject<UITTTableBase>(this, Row->ITTTableClass);
			if (ITTTable)
			{
				ITTTable->AddToRoot();
				ITTTable->BuiltInInitialize(Row->DataTable);
		
				ITTTables.Emplace(RowName, ITTTable);
			}
		}
	}
}

void UITTTableManager::DestroyITTTables()
{
	for (auto& Iter : ITTTables)
	{
		if (bInitialized)
		{
			Iter.Value->Finalize();
		}
		
		Iter.Value->RemoveFromRoot();
		ITTDeleteObject(Iter.Value);
	}

	ITTTables.Empty();
}


UDataTable* UITTTableManager::GetDataTable(const FName& TableName)
{
	UITTTableBase* ITTTable = GetITTTable<UITTTableBase>(TableName);
	if (!IsValid(ITTTable))
	{
		return nullptr;
	}

	UDataTable* DataTable = ITTTable->GetDataTable();
	if (!IsValid(DataTable))
	{
		ITTCHECKF(false, TEXT("[%s] Couldn't find DataTable [TableName : %s]"), *ITTSTRING_CLASS_FUNC, *TableName.ToString());
		return nullptr;
	}
	
	return DataTable;
}
// ============================ //