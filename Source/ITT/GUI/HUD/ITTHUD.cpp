// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTHUD.h"

#include "GameBase//GameManager/ITTWidgetManager.h"
#include "GUI/Widget/ITTWidget.h"


AITTHUD::AITTHUD(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer), bBegin(false)
{
    HudKeyToDefalutActivation.Empty();
    HudWidgets.Empty();
    ActivatedHudWidgets.Empty();
}


void AITTHUD::BeginPlay()
{
    Super::BeginPlay();

    if (!bBegin)
    {
        CreateHudWidgets();
        
        bBegin = true;
    }
}

void AITTHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    CloseHudWidgets();
}


// ========== Hud Widget ========== //
void AITTHUD::CreateHudWidgets()
{
    HudWidgets.Empty();
    ActivatedHudWidgets.Empty();

    TArray<FName> Keys;
    HudKeyToDefalutActivation.GetKeys(Keys);
		
    for(const FName& Key : Keys)
    {
        UITTWidgetManager* WidgetManager = UITTWidgetManager::GetInstance();
        ITTCHECK(WidgetManager != nullptr);

        TObjectPtr<UITTWidget> HudWidget = WidgetManager->ITTCreateWidget(Key);
        ITTCHECK(IsValid(HudWidget));
			
        HudWidgets.Emplace(Key, HudWidget);

        if (*HudKeyToDefalutActivation.Find(Key))
        {
            ChangeHudActivation(Key, true);
        }
    }
}

void AITTHUD::CloseHudWidgets()
{
    for (auto& HudWidget : HudWidgets)
    {
        if (HudWidget.Value->IsValidLowLevel())
        {
            HudWidget.Value->ITTCloseWidget(true);
        }
    }

    HudWidgets.Empty();
    ActivatedHudWidgets.Empty();
}

void AITTHUD::ChangeHudActivation(const FName& HudKey, bool bActive)
{
    if (HudWidgets.Contains(HudKey))
    {
        TWeakObjectPtr<UITTWidget> HudWidget = *HudWidgets.Find(HudKey);

        if (HudWidget->IsValidLowLevel())
        {
            HudWidget->ChangeActivation(bActive);

            if (bActive)
            {
                ActivatedHudWidgets.Emplace(HudKey, HudWidget);
            }
            else
            {
                if (ActivatedHudWidgets.Contains(HudKey))
                {
                    ActivatedHudWidgets.Remove(HudKey);
                }
            }
        }
    }
}
// ================================ //