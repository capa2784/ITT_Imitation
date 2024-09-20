// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTPlayerController_LocalMultiplay.h"

#include "Engine/LocalPlayer.h"


AITTPlayerController_LocalMultiplay::AITTPlayerController_LocalMultiplay(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


void AITTPlayerController_LocalMultiplay::PreInitialize(ULocalPlayer* LocalPlayer)
{
	Super::PreInitialize(LocalPlayer);
	
	if (LocalPlayer->GetPlatformUserId().GetInternalId() == 0)
	{
		PlayerCharacter = EITTCharacter_Player::Cody;
	}
	else
	{
		PlayerCharacter = EITTCharacter_Player::May;
	}
}
