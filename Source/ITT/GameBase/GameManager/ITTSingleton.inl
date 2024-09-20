// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTSingleton.h"

#include "UObject/UObjectGlobals.h"


// ========== Instance ========== //
template <typename TClass>
TClass* TITTSingleton<TClass>::CreateInstance()
{
	if (!Instance)
	{
		Instance = ITTNewObject<TClass>();
		if (Instance)
		{
			Instance->AddToRoot();
		}
	}

	return Instance;
}

template <typename TClass>
void TITTSingleton<TClass>::DestroyInstance()
{
	if (Instance && Instance->IsValidLowLevel())
	{
		Instance->RemoveFromRoot();
		ITTDeleteObject(Instance);
	}
}

template <typename TClass>
TClass* TITTSingleton<TClass>::GetInstance()
{
	return Instance;
}

template <typename TClass>
bool TITTSingleton<TClass>::HasInstance()
{
	return Instance != nullptr && !Instance->HasAnyFlags(RF_FinishDestroyed);
}
// ============================== //