// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTGameMode_LocalMultiplay.h"

#include "Kismet/GameplayStatics.h"


AITTGameMode_LocalMultiplay::AITTGameMode_LocalMultiplay()
{
}


// ========== Player ========== //
void AITTGameMode_LocalMultiplay::AdjustPlayer()
{
	UGameplayStatics::CreatePlayer(this, 1);
}
// ============================ //