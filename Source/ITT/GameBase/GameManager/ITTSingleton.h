// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
// ========== Life Cycle ========== //
class IITTSingleton
{
public:
	IITTSingleton() {}
	virtual ~IITTSingleton() {}

	virtual void BuiltInInitialize() {}
	virtual void Initialize() {}
	virtual void PostInitialize() {}
	virtual void PreFinalize() {}
	virtual void Finalize() {}
	virtual void BuiltInFinalize() {}

	virtual void Tick(float DeltaTime) {}
};
// ================================ //


// ========== Instance ========== //
template<typename TClass>
class ITT_API TITTSingleton : public IITTSingleton
{
public:
	static TClass* CreateInstance();
	static void DestroyInstance();
	
	static TClass* GetInstance();
	static bool HasInstance();

protected:
	static TClass* Instance;
};

template<typename TClass>
TClass* TITTSingleton<TClass>::Instance = nullptr;
// ============================== //


#include "ITTSingleton.inl"
