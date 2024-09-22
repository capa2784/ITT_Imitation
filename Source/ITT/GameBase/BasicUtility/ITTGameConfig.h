// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ITTGameConfig.generated.h"

/**
 * 
 */
UCLASS(Config=Game)
class ITT_API UITTGameConfig : public UObject
{
	GENERATED_BODY()

public:
	UITTGameConfig();

	
	// ==================== Getter ==================== //
	// ========== Table ========== //
	const FString& GetTableListPath() const { return TableListPath; }
	// =========================== //

	
	// ========== Scene ========== //
	uint32 GetFirstSceneIndex() const { return FirstSceneIndex; }
	// =========================== //
	// ================================================ //

	
private:
	// ========== Table ========== //
	UPROPERTY(Config)
	FString TableListPath;
	// =========================== //

	
	// ========== Scene ========== //
	UPROPERTY(Config)
	uint32 FirstSceneIndex;
	// =========================== //
};