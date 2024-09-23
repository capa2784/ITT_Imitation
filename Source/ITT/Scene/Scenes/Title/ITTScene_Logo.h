// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Scene/ITTSceneBase.h"
#include "ITTScene_Logo.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTScene_Logo : public UITTSceneBase
{
	GENERATED_BODY()

public:
	UITTScene_Logo();

	
	virtual void Initialize(EITTSceneType _SceneType) override;
	virtual void Finalize() override;
	virtual void Tick(float DeltaTime) override;
};
