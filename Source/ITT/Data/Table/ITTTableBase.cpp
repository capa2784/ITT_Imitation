// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTTableBase.h"

#include "Engine/DataTable.h"


UITTTableBase::UITTTableBase()
	: DataTable(nullptr)
{
}


void UITTTableBase::BuiltInInitialize(UDataTable* _DataTable)
{
	DataTable = _DataTable;
}

void UITTTableBase::Initialize()
{
}

void UITTTableBase::Finalize()
{
	DataTable = nullptr;
}