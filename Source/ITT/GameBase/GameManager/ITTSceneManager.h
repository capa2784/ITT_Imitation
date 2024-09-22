// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ITTSingleton.h"
#include "GameBase/ITTDefine_GameBase.h"
#include "ITTSceneManager.generated.h"

/**
 * 
 */
DECLARE_DELEGATE(FITTEndLoadingDelegate);


UCLASS()
class ITT_API UITTSceneManager : public UObject, public TITTSingleton<UITTSceneManager>
{
	GENERATED_BODY()

public:
	UITTSceneManager();
	
	
	virtual void BuiltInInitialize() override;
	virtual void Initialize() override;
	virtual void PostInitialize() override;
	virtual void PreFinalize() override;
	virtual void Finalize() override;
	virtual void BuiltInFinalize() override;
	
	virtual void Tick(float DeltaTime) override;


private:
	// ========== Helper ========== //
	void CreateHelper();
	void DestroyHelper();
	// ============================ //

	
	// ========== Scene State Machine ========== //
	void CreateSceneStateMachine();
	void DestroySceneStateMachine();

public:
	void ChangeScene(EITTSceneType NextSceneType, EITTLoadingType LoadingType, bool bImmediately = false);

private:
	void ChangeSceneState(EITTLoadingType LoadingType);
	void OnChangeSceneState(int64 PreviousSceneId, int64 CurrentSceneId);

	TObjectPtr<class UITTSceneBase> CreateScene(EITTSceneType SceneType);
	void DestroyScene(TWeakObjectPtr<class UITTSceneBase> Scene);

	bool TryOpenLevel(const FITTOnLoadLevelComplete& Delegate, EITTSceneType PreviousSceneType, EITTSceneType CurrentSceneType);
	// ========================================= //

	
	// ========== Scene ========== //
	void LoadFirstScene();
	// =========================== //
	
	
private:
	// ========== Helper ========== //
	TObjectPtr<class UITTLoadingHelper> LoadingHelper;
	TObjectPtr<class UITTSceneHelper> SceneHelper;
	// ============================ //

	
	// ========== Scene State Machine ========== //
	TObjectPtr<class UITTStateMachine> SceneStateMachine;
	// ========================================= //
	
	
	// ========== Scene ========== //
	TObjectPtr<class UITTSceneBase> CurrentScene;
	// =========================== //
	

	// ==================== Delegate ==================== //
	// ========== Loading ========== //
	FITTEndLoadingDelegate EndLoadingDelegate;
	// ============================= //
	// ================================================== //


#define SceneMgr UITTSceneManager::GetInstance()
};
