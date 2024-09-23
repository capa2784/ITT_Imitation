// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTScene_Logo.h"

#include "GameBase/GameManager/ITTWidgetManager.h"
#include "GUI/Widget/Title/ITTWidget_Logo.h"


UITTScene_Logo::UITTScene_Logo()
{
}


void UITTScene_Logo::Initialize(EITTSceneType _SceneType)
{
	Super::Initialize(_SceneType);

	if (WidgetMgr)
	{
		TObjectPtr<UITTWidget> Widget = WidgetMgr->ITTCreateWidget(UITTWidget_Logo::GetClassWidgetKey());

		if (IsValid(Widget))
		{
			Widget->ChangeActivation(true);
		}
	}
}

void UITTScene_Logo::Finalize()
{
	if (WidgetMgr)
	{
		WidgetMgr->ITTDestroyWidget(UITTWidget_Logo::GetClassWidgetKey());
	}
	
	Super::Finalize();
}

void UITTScene_Logo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
