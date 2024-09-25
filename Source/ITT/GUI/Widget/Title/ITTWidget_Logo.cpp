// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTWidget_Logo.h"

#include "Animation/WidgetAnimation.h"
#include "GameBase/GameManager/ITTSceneManager.h"


UITTWidget_Logo::UITTWidget_Logo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), bWAnimFinished(false), WAnim_Appearance(nullptr), WAnim_Disappearance(nullptr)
{
}


void UITTWidget_Logo::NativeConstruct()
{
	Super::NativeConstruct();

	StartLogoAnimation();
}

void UITTWidget_Logo::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (bWAnimFinished)
	{
		bWAnimFinished = false;
		ChangeScene();
	}
}


// ========== Widget Animation ========== //
void UITTWidget_Logo::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	Super::OnAnimationFinished_Implementation(Animation);
	
	if (Animation == WAnim_Appearance)
	{
		if (WAnim_Disappearance->IsValidLowLevel())
		{
			PlayAnimation(WAnim_Disappearance);
			return;
		}
	}
	
	bWAnimFinished = true;
}

void UITTWidget_Logo::StartLogoAnimation()
{
	if (WAnim_Appearance->IsValidLowLevel())
	{
		PlayAnimation(WAnim_Appearance);
	}
}
// ====================================== //


// ========== Finish ========== //
void UITTWidget_Logo::ChangeScene()
{
	if (SceneMgr)
	{
		SceneMgr->ChangeScene(EITTSceneType::Title, EITTLoadingType::None, true);
	}
}
// ============================ //