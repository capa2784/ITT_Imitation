// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Character/ITTDefine_Character.h"
#include "ITTAnimationHelperComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=ITTComponent, meta=(BlueprintSpawnableComponent))
class ITT_API UITTAnimationHelperComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UITTAnimationHelperComponent();

	
protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	
	// ========== Anim Data ========== //
	class UITTData_SubAnim* GetSubAnimData(const FITTMovementMode& MovementMode) const;

	TSubclassOf<class UAnimInstance> GetSubAnimInstanceClass(const FITTMovementMode& MovementMode) const;
	// =============================== //

	
private:
	// ========== Anim Data ========== //
	UPROPERTY(Category=ITT, EditAnywhere)
	TMap<FITTMovementMode, class UITTData_SubAnim*> SubAnimDatas;
	// =============================== //
};
