// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ITTInputHelperComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=ITTComponent, meta=(BlueprintSpawnableComponent))
class ITT_API UITTInputHelperComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UITTInputHelperComponent();


protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	
	// ========== Input ========== //
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	
	// -- Movement -- //
	void InputMove(const struct FInputActionValue& Value);

	void InputJump(const struct FInputActionValue& Value);
	void InputStopJumping(const struct FInputActionValue& Value);
	
	void InputLook(const struct FInputActionValue& Value);

	void InputDash(const struct FInputActionValue& Value);
	
	void InputGroundPound_Crouch(const struct FInputActionValue& Value);
	void InputStopGroundPound_Crouch(const struct FInputActionValue& Value);

	void InputSwing_GrindGrapple(const struct FInputActionValue& Value);
	void InputStopSwing_GrindGrapple(const struct FInputActionValue& Value);

	void InputToggleSprint(const struct FInputActionValue& Value);
	void InputStopToggleSprint(const struct FInputActionValue& Value);
	

	// -- Ability -- //
	void InputAbility1_Fire(const struct FInputActionValue& Value);
	void InputStopAbility1_Fire(const struct FInputActionValue& Value);

	void InputAbility2_Aim(const struct FInputActionValue& Value);
	void InputStopAbility2_Aim(const struct FInputActionValue& Value);

	void InputInteract(const struct FInputActionValue& Value);

	void InputCancel(const struct FInputActionValue& Value);

	void InputFindOtherPlayer(const struct FInputActionValue& Value);
	// =========================== //

	
private:
	// ========== Owner ========== //
	TWeakObjectPtr<class AITTCharacter_Player> Character;
	// =========================== //

	
	// ========== Input ========== //
	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* MappingContext;
	
	// -- Movement -- //
	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;
	
	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* DashAction;

	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* GroundPound_Crouch_Action;

	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* Swing_GrindGrapple_Action;

	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ToggleSprintAction;

	
	// -- Ability-- //
	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* Ability1_Fire_Action;

	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* Ability2_Aim_Action;

	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InteractAction;
	
	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* CancelAction;

	UPROPERTY(Category = ITT, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UInputAction* FindOtherPlayerAction;
	// =========================== //
};