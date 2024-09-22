// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ITTSingleton.h"
#include "GameBase/ITTDefine_GameBase.h"
#include "ITTLevelManager.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTLevelManager : public UObject, public TITTSingleton<UITTLevelManager>
{
	GENERATED_BODY()

public:
	UITTLevelManager();
	

	// ========== Open Level ========== //
	bool OpenLevelByTable(const FITTOnLoadLevelComplete& Delegate, const FName& LevelName);

private:
	bool OpenLevelByPath(const FITTOnLoadLevelComplete& Delegate, const FName& LevelPath = FName(), bool bAbsolute = true);
	bool OpenLevelBySoftObjectPtr(const FITTOnLoadLevelComplete& Delegate, const TSoftObjectPtr<UWorld>& LevelSoftObject, bool bAbsolute = true);
	// ================================ //


public:
	// ========== Complete ========== //
	void LoadLevelComplete();
	// ============================== //
	
	
private:
	// ========== Level ========== //
	FName CurrentLevelName;
	// =========================== //

	
public:
	// ==================== Delegate ==================== //
	// ========== Complete ========== //
	FITTOnLoadLevelComplete OnLoadLevelComplete;
	// ============================== //
	// ================================================== //
	
	
#define LevelMgr UITTLevelManager::GetInstance()
};
