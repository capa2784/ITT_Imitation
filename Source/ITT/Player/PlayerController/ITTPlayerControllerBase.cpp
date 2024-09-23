// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTPlayerControllerBase.h"


AITTPlayerControllerBase::AITTPlayerControllerBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set mouse cursor
	SetShowMouseCursor(true);
	DefaultMouseCursor = EMouseCursor::Default;
	CurrentMouseCursor = EMouseCursor::Default;
}


void AITTPlayerControllerBase::PreInitialize(ULocalPlayer* LocalPlayer)
{
}
