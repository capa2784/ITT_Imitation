// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTLoadingHelper.h"


UITTLoadingHelper::UITTLoadingHelper()
	: bInitialized(false)
{
}


void UITTLoadingHelper::Initialize()
{
	if (!bInitialized)
	{
		{
			
		}
		
		bInitialized = true;
	}
}

void UITTLoadingHelper::Deinitialize()
{
	if (!bInitialized)
	{
		return;
	}
}


// ========== Loading ========== //
bool UITTLoadingHelper::StartLoading(EITTLoadingType LoadingType)
{
	if (!bInitialized)
	{
		return false;
	}

	return true;
}

void UITTLoadingHelper::EndLoading(EITTLoadingType LoadingType)
{
	if (!bInitialized)
	{
		return;
	}
}
// ============================= //