﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTCharacterBase.h"

#include "Component/Character/Movement/ITTCharacterMovementComponent.h"
#include "Component/Character/Stat/ITTCharacterStatComponent.h"
#include "Component/Character/Animation/ITTAnimationHelperComponent.h"


AITTCharacterBase::AITTCharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UITTCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Create character stat component
	CharacterStatComponent = CreateDefaultSubobject<UITTCharacterStatComponent>(TEXT("CharacterStatComponent"));

	// Create animation helper component
	AnimationHelperComponent = CreateDefaultSubobject<UITTAnimationHelperComponent>(TEXT("AnimationHelperComponent"));
}


void AITTCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AITTCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}