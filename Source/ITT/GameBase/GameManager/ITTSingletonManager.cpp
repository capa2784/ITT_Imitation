// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTSingletonManager.h"

#include "ITTSingleton.h"

#include "ITTTableManager.h"


TObjectPtr<UITTSingletonManager> UITTSingletonManager::Instance = nullptr;


UITTSingletonManager::UITTSingletonManager()
	: bBuiltInInitialized(false), bInitialized(false)
{
}


// ========== Instance ========== //
TObjectPtr<UITTSingletonManager> UITTSingletonManager::CreateInstance()
{
	Instance = ITTNewObject<UITTSingletonManager>();
	if (Instance)
	{
		Instance->AddToRoot();
		Instance->RegisterSingletons();
		Instance->RegisterSingletonsForTick();
	}
	
	return Instance;
}

void UITTSingletonManager::DestroyInstance()
{
	if (IsValid(Instance))
	{
		Instance->UnregisterSingletons();
		Instance->RemoveFromRoot();
		ITTDeleteObject(Instance);
	}
}
// ============================== //


// ========== Singletons ========== //
void UITTSingletonManager::BuiltInInitializeSingletons()
{
	if (!bBuiltInInitialized)
	{
		for (IITTSingleton* Singleton : Singletons)
		{
			Singleton->BuiltInInitialize();
		}

		bBuiltInInitialized = true;
	}
}

void UITTSingletonManager::InitializeSingletons()
{
	if (!bInitialized)
	{
		for (IITTSingleton* Singleton : Singletons)
		{
			Singleton->Initialize();
		}

		for (IITTSingleton* Singleton : Singletons)
		{
			Singleton->PostInitialize();
		}
		
		bInitialized = true;
	}
}

void UITTSingletonManager::FinalizeSingletons()
{
	for (IITTSingleton* Singleton : Singletons)
	{
		if (bInitialized)
		{
			Singleton->PreFinalize();
			Singleton->Finalize();
		}
	}

	bInitialized = false;
	
	for (IITTSingleton* Singleton : Singletons)
	{
		if (bBuiltInInitialized)
		{
			Singleton->BuiltInFinalize();
		}
	}
	
	bBuiltInInitialized = false;
}

void UITTSingletonManager::TickSingletons(float DeltaTime)
{
	if (bInitialized)
	{
		for (IITTSingleton* Singleton : SingletonsForTick)
		{
			Singleton->Tick(DeltaTime);
		}
	}
}

void UITTSingletonManager::RegisterSingletons()
{
	Singletons.Reset();
	
	// Singletons.Emplace([Class]::CreateInstance());
	Singletons.Emplace(UITTTableManager::CreateInstance());
}

void UITTSingletonManager::RegisterSingletonsForTick()
{
	SingletonsForTick.Reset();
	
	// SingletonsForTick.Emplace([Class]::CreateInstance());
}

void UITTSingletonManager::UnregisterSingletons()
{
	Singletons.Reset();
	SingletonsForTick.Reset();
	
	// [Class]::DestroyInstance();
	UITTTableManager::DestroyInstance();
}
// ================================ //