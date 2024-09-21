// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTCharacter_Player.h"

#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "Component/Character/Input/ITTInputHelperComponent.h"
#include "Component/Character/Movement/ITTCharacterMovementComponent_Player.h"


AITTCharacter_Player::AITTCharacter_Player(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UITTCharacterMovementComponent_Player>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(40.f, 100.0f);
		
	// Set use controller rotaion
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	// Create a camera boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	
	// Create input helper component
	InputHelperComponent = CreateDefaultSubobject<UITTInputHelperComponent>(TEXT("InputHelperComponent"));
}


void AITTCharacter_Player::BeginPlay()
{
	Super::BeginPlay();
}

void AITTCharacter_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// ========== Input ========== //
void AITTCharacter_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	InputHelperComponent->SetupPlayerInputComponent(PlayerInputComponent);
}
// =========================== //