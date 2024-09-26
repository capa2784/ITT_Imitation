// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTTextBlock.h"

#include "Engine/Engine.h"

#include "GameBase/Option/ITTGameUserSettings.h"

#include "GameBase/GameManager/ITTTableManager.h"
#include "Data/Table/Tables/GUI/ITTTable_String.h"


UITTTextBlock::UITTTextBlock()
	: StringIndex(-1)
{
}


TSharedRef<SWidget> UITTTextBlock::RebuildWidget()
{
	return Super::RebuildWidget();
}

void UITTTextBlock::SynchronizeProperties()
{
	OnChangeStringIndex();
	
	Super::SynchronizeProperties();
}

void UITTTextBlock::OnTextChanged()
{
	Super::OnTextChanged();
}

void UITTTextBlock::OnFontChanged()
{
	Super::OnFontChanged();
}


// ==================== Getter / Setter ==================== //
// ========== String Index ========== //
void UITTTextBlock::SetStringIndex(int32 _StringIndex)
{
	StringIndex = _StringIndex;
	OnChangeStringIndex();
}
// ================================== //
// ========================================================= //


// ========== String Index ========== //
void UITTTextBlock::OnChangeStringIndex()
{
	if (TableMgr == nullptr)
	{
		return;
	}
	
	UITTTable_String* StringTable = TableMgr->GetITTTable<UITTTable_String>(UITTTable_String::GetTableName());
	if (StringTable == nullptr)
	{
		return;
	}

	UITTGameUserSettings* ITTUserSettings = Cast<UITTGameUserSettings>(GEngine->GetGameUserSettings());
	if (ensure(ITTUserSettings))
	{
		FString OutString;
		StringTable->GetString(OutString, StringIndex, ITTUserSettings->GetLanguage());

		SetText(FText::FromString(OutString));
	}
}
// ================================== //