// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character/ITTDefine_Character.h"
#include "ITTCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API AITTCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AITTCharacterBase(const FObjectInitializer& ObjectInitializer);

	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};