// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTCharacterBase.h"

#include "Component/Character/Movement/ITTCharacterMovementComponent.h"


AITTCharacterBase::AITTCharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UITTCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;
}


void AITTCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AITTCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}