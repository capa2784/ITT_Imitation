// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTScene_Title.h"

#include "GameBase/GameManager/ITTWidgetManager.h"
#include "GUI/Widget/Title/ITTWidget_Title.h"


UITTScene_Title::UITTScene_Title()
{
}


void UITTScene_Title::Initialize(EITTSceneType _SceneType)
{
	Super::Initialize(_SceneType);

	if (WidgetMgr)
	{
		TObjectPtr<UITTWidget> Widget = WidgetMgr->ITTCreateWidget(UITTWidget_Title::GetClassWidgetKey());

		if (IsValid(Widget))
		{
			Widget->ChangeActivation(true);
		}
	}
}

void UITTScene_Title::Finalize()
{
	if (WidgetMgr)
	{
		WidgetMgr->ITTDestroyWidget(UITTWidget_Title::GetClassWidgetKey());
	}
	
	Super::Finalize();
}

void UITTScene_Title::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
