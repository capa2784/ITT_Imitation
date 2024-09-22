// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTSceneHelper.h"

#include "GameBase/BasicUtility/ITTBasicUtility.h"


UITTSceneHelper::UITTSceneHelper()
	: bInitialized(false)
{
}


void UITTSceneHelper::Initialize()
{
	if (!bInitialized)
	{
		{
			
		}
		
		bInitialized = true;
	}
}

void UITTSceneHelper::Deinitialize()
{
	if (!bInitialized)
	{
		return;
	}
}

EITTSceneType UITTSceneHelper::GetFirstSceneType() const
{
	return static_cast<EITTSceneType>(UITTBasicUtility::GetFirstSceneIndex());
}