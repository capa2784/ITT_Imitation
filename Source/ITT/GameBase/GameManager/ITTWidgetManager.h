// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ITTSingleton.h"
#include "ITTWidgetManager.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTWidgetManager : public UObject, public TITTSingleton<UITTWidgetManager>
{
	GENERATED_BODY()

public:
	UITTWidgetManager();
	

	virtual void BuiltInInitialize() override;
	virtual void Initialize() override;
	virtual void Finalize() override;

	
public:
	// ========== Create Widget ========== //
	TObjectPtr<class UITTWidget> ITTCreateWidget(const FName& WidgetName, APlayerController* WidgetOwner = nullptr, bool bManaged = true, const FName& ManagedWidgetKey = FName());

	template<typename T>
	TObjectPtr<T> ITTCreateWidget(const FName& WidgetName, APlayerController* WidgetOwner = nullptr, bool bManaged = true, const FName& ManagedWidgetKey = FName())
	{
		TObjectPtr<class UITTWidget> Widget = ITTCreateWidget(WidgetName, WidgetOwner, bManaged, ManagedWidgetKey);
		if (Widget == nullptr)
		{
			return nullptr;
		}
		
		return Cast<T>(Widget);
	}

private:
	TObjectPtr<class UITTWidget> ITTCreateWidget_Internal(const FName& WidgetName, APlayerController* WidgetOwner, bool bManaged, const FName& ManagedWidgetKey);
	// =================================== //

	
public:
	// ========== Destroy Widget ========== //
	bool ITTDestroyWidget(const FName& ManagedWidgetKey, bool bImmediately = false);
	// ==================================== //
	
	
private:
	bool bBuiltInInitialized;
	bool bInitialized;

	
	UPROPERTY()
	TMap<FName, TWeakObjectPtr<UITTWidget>> ManagedWidgets;


#define WidgetMgr UITTWidgetManager::GetInstance()
};
