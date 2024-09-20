// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTPlayerControllerBase.h"


AITTPlayerControllerBase::AITTPlayerControllerBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), PlayerCharacter(EITTCharacter_Player::Cody)
{
}


void AITTPlayerControllerBase::PreInitialize(ULocalPlayer* LocalPlayer)
{
}
