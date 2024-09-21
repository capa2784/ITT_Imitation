// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTCharacterMovementComponent_Player.h"


UITTCharacterMovementComponent_Player::UITTCharacterMovementComponent_Player()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UITTCharacterMovementComponent_Player::BeginPlay()
{
	Super::BeginPlay();
}

void UITTCharacterMovementComponent_Player::TickComponent(float DeltaTime, ELevelTick TickType,
												   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}