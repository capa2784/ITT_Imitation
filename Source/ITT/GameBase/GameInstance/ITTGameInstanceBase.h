// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Containers/Ticker.h"
#include "GameBase/ITTDefine_GameBase.h"
#include "ITTGameInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

public:
	UITTGameInstanceBase();
	virtual ~UITTGameInstanceBase() override;
	
	
	virtual void Init() override;
	virtual void Shutdown() override;
	
	virtual void OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld) override;
	virtual void LoadComplete(const float LoadTime, const FString& MapName) override;
	
	virtual bool Tick(float DeltaSeconds);
	
	void OnStartGameInstance(UGameInstance* GameInstance);
	
	
private:
	// ========== Launch Process ========== //
	void ProcessInitialize();
	void ProcessFinalize();
	
	bool CreateBasicUtility();
	void DestroyBasicUtility();
	
	bool CreateGameManagers();
	void InitializeGameManagers();
	void TickGameManagers(float DeltaSeconds);
	void DestroyGameManagers();
	
	bool RegisterTick();
	void UnregisterTick();
	// ==================================== //
	
	
private:
	FTSTicker::FDelegateHandle TickDelegateHandle;
	
	
	// ========== Launch Process ========== //
	EITTLaunchProcess LaunchProcess;
	// ==================================== //
};