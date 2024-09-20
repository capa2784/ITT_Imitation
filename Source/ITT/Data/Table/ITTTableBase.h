// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ITTTableBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ITT_API UITTTableBase : public UObject
{
	GENERATED_BODY()

public:
	UITTTableBase();

	
	virtual void BuiltInInitialize(class UDataTable* _DataTable);
	
	virtual void Initialize();

	virtual void Finalize();


	// ==================== Getter ==================== //
	// ========== Table ========== //
	UDataTable* GetDataTable() const { return DataTable; }
	// =========================== //
	// ================================================ //

	
protected:
	// ========== Table ========== //
	UPROPERTY()
	UDataTable* DataTable;
	// =========================== //
};