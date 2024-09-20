// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ITTSingletonManager.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTSingletonManager : public UObject
{
	GENERATED_BODY()

public:
	UITTSingletonManager();

	
	// ========== Instance ========== //
	static TObjectPtr<UITTSingletonManager> CreateInstance();
	static void DestroyInstance();
	
	static TObjectPtr<UITTSingletonManager> GetInstance() { return Instance; }
	// ============================== //
	

	// ========== Singletons ========== //
	void BuiltInInitializeSingletons();
	void InitializeSingletons();
	void FinalizeSingletons();
	
	void TickSingletons(float DeltaTime);
	
private:
	void RegisterSingletons();
	void RegisterSingletonsForTick();
	void UnregisterSingletons();
	// ================================ //
	
	
private:
	// ========== Instance ========== //
	static TObjectPtr<UITTSingletonManager> Instance;
	// ============================== //
	
	
	// ========== Singletons ========== //
	bool bBuiltInInitialized;
	bool bInitialized;
	
	TArray<class IITTSingleton*> Singletons;
	TArray<class IITTSingleton*> SingletonsForTick;
	// ================================ //
};