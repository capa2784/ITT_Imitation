// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTTable_Level.h"


UITTTable_Level::UITTTable_Level()
{
}


// ========== Level ========== //
const FName& UITTTable_Level::GetLevelPath(const FName& LevelName) const
{
	FITTTableRow_Level* Row = GetDataTable()->FindRow<FITTTableRow_Level>(LevelName, ITTTEXT_CLASS_FUNC);
	return Row->LevelPath;
}

const TSoftObjectPtr<UWorld>& UITTTable_Level::GetSoftObject(const FName& LevelName) const
{
	FITTTableRow_Level* Row = GetDataTable()->FindRow<FITTTableRow_Level>(LevelName, ITTTEXT_CLASS_FUNC);
	return Row->SoftObject;
}
// =========================== //