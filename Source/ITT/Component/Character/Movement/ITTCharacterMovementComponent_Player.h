// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITTCharacterMovementComponent.h"
#include "ITTCharacterMovementComponent_Player.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=ITTComponent, meta=(BlueprintSpawnableComponent))
class ITT_API UITTCharacterMovementComponent_Player : public UITTCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UITTCharacterMovementComponent_Player();
	

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
};