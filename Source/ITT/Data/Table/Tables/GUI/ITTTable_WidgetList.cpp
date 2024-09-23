// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTTable_WidgetList.h"


UITTTable_WidgetList::UITTTable_WidgetList()
{
}


// ========== Widget ========== //
void UITTTable_WidgetList::GetWidgetClass(const FName& WidgetName, TSubclassOf<UITTWidget>& OutClass) const
{
	FITTTableRow_WidgetList* Row = GetDataTable()->FindRow<FITTTableRow_WidgetList>(WidgetName, ITTTEXT_CLASS_FUNC);
	if (Row)
	{
		OutClass = Row->ITTWidgetClass;
	}
}

int32 UITTTable_WidgetList::GetZOrder(const FName& WidgetName) const
{
	FITTTableRow_WidgetList* Row = GetDataTable()->FindRow<FITTTableRow_WidgetList>(WidgetName, ITTTEXT_CLASS_FUNC);
	if (Row)
	{
		return Row->ZOrder;
	}

	return 0;
}
// ============================ //