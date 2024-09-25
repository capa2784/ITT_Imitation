// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTWidget_Title.h"

#include "Kismet/KismetSystemLibrary.h"

#include "Animation/WidgetAnimation.h"

#include "GameBase/GameManager/ITTSceneManager.h"

#include "GUI/UMGComponent/ITTButton.h"


UITTWidget_Title::UITTWidget_Title(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), bWAnimFinished(false), WAnim_Appearance(nullptr)
{
}


void UITTWidget_Title::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	BindButtons();
}

void UITTWidget_Title::NativeConstruct()
{
	Super::NativeConstruct();

	StartLogoAnimation();
}

void UITTWidget_Title::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}


// ========== Widget Animation ========== //
void UITTWidget_Title::StartLogoAnimation()
{
	if (WAnim_Appearance->IsValidLowLevel())
	{
		PlayAnimation(WAnim_Appearance);
	}
}
// ====================================== //


// ========== Button ========== //
void UITTWidget_Title::BindButtons()
{
	BTN_LocalPlay->OnClicked().AddUObject(this, &UITTWidget_Title::OnClickButton_LocalPlay);
	BTN_OnlinePlay->OnClicked().AddUObject(this, &UITTWidget_Title::OnClickButton_OnlinePlay);
	BTN_Option->OnClicked().AddUObject(this, &UITTWidget_Title::OnClickButton_Option);
	BTN_AccessibilityOptions->OnClicked().AddUObject(this, &UITTWidget_Title::OnClickButton_AccessibilityOptions);
	BTN_Credits->OnClicked().AddUObject(this, &UITTWidget_Title::OnClickButton_Credits);
	BTN_Quit->OnClicked().AddUObject(this, &UITTWidget_Title::OnClickButton_Quit);
}


void UITTWidget_Title::OnClickButton_LocalPlay()
{
	if (SceneMgr)
	{
		SceneMgr->ChangeScene(EITTSceneType::LocalPlay_SelectInput, EITTLoadingType::None, true);
	}
}

void UITTWidget_Title::OnClickButton_OnlinePlay()
{
}

void UITTWidget_Title::OnClickButton_Option()
{
}

void UITTWidget_Title::OnClickButton_AccessibilityOptions()
{
}

void UITTWidget_Title::OnClickButton_Credits()
{
}

void UITTWidget_Title::OnClickButton_Quit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
// ============================ //
