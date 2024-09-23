// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ITTHUD.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API AITTHUD : public AHUD
{
	GENERATED_BODY()

public:
    AITTHUD(const FObjectInitializer& ObjectInitializer);

    
protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


    // ========== Hud Widget ========== //
    void CreateHudWidgets();
    void CloseHudWidgets();
    
public:
    void ChangeHudActivation(const FName& HudKey, bool bActive);
    // ================================ //
    
    
protected:
    bool bBegin;


    // ========== Hud Widget ========== //
    UPROPERTY(Category=ITT, EditAnywhere)
    TMap<FName, bool> HudKeyToDefalutActivation;

    UPROPERTY()
    TMap<FName, TWeakObjectPtr<class UITTWidget>> HudWidgets;

    UPROPERTY()
    TMap<FName, TWeakObjectPtr<class UITTWidget>> ActivatedHudWidgets;
    // ================================ //
};
