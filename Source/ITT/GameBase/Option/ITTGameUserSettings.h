// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "GUI/ITTDefine_GUI.h"
#include "ITTGameUserSettings.generated.h"

/**
 * 
 */
UCLASS(Config=GameUserSettings, configdonotcheckdefaults)
class ITT_API UITTGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

	
public:
	// ========== Language ========== //
	UFUNCTION(Category=ITT, BlueprintPure)
	EITTLanguage GetLanguage() const { return Language; }
	// ============================== //
	
	
protected:
	// ========== Language ========== //
	UPROPERTY(Config)
	EITTLanguage Language;
	// ============================== //
};
