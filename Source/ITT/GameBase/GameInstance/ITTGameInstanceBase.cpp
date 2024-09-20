// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTGameInstanceBase.h"

#include "Engine/World.h"


UITTGameInstanceBase::UITTGameInstanceBase()
{
	FWorldDelegates::OnStartGameInstance.AddUObject(this, &UITTGameInstanceBase::OnStartGameInstance);
}

UITTGameInstanceBase::~UITTGameInstanceBase()
{
	FWorldDelegates::OnStartGameInstance.RemoveAll(this);
}


void UITTGameInstanceBase::Init()
{
	Super::Init();

	ProcessInitialize();
	ITTCHECK(LaunchProcess == EITTLaunchProcess::ProcessFinished);
}

void UITTGameInstanceBase::Shutdown()
{
	ProcessFinalize();
	
	Super::Shutdown();
}

void UITTGameInstanceBase::OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld)
{
	Super::OnWorldChanged(OldWorld, NewWorld);
}

void UITTGameInstanceBase::LoadComplete(const float LoadTime, const FString& MapName)
{
	Super::LoadComplete(LoadTime, MapName);
}

bool UITTGameInstanceBase::Tick(float DeltaSeconds)
{
	if (LaunchProcess == EITTLaunchProcess::ProcessFinished)
	{
		LaunchProcess = EITTLaunchProcess::End;
	}

	TickGameManagers(DeltaSeconds);
	
	return true;
}

void UITTGameInstanceBase::OnStartGameInstance(UGameInstance* GameInstance)
{
	InitializeGameManagers();
}


// ==========  Launch Process ========== //
void UITTGameInstanceBase::ProcessInitialize()
{
	LaunchProcess = EITTLaunchProcess::CreateBasicUtility;
	if (CreateBasicUtility() == false)
	{
		return;
	}
	
	LaunchProcess = EITTLaunchProcess::CreateGameManager;
	if (CreateGameManagers() == false)
	{
		return;
	}
	
	LaunchProcess = EITTLaunchProcess::RegisterTick;
	if (RegisterTick() == false)
	{
		return;
	}
	
	LaunchProcess = EITTLaunchProcess::ProcessFinished;
}

void UITTGameInstanceBase::ProcessFinalize()
{
	if (LaunchProcess > EITTLaunchProcess::RegisterTick)
	{
		UnregisterTick();
	}

	if (LaunchProcess > EITTLaunchProcess::CreateGameManager)
	{
		DestroyGameManagers();
	}

	if (LaunchProcess > EITTLaunchProcess::CreateBasicUtility)
	{
		DestroyBasicUtility();
	}
}

bool UITTGameInstanceBase::CreateBasicUtility()
{
	return true;
}

void UITTGameInstanceBase::DestroyBasicUtility()
{
}

bool UITTGameInstanceBase::CreateGameManagers()
{
	return true;
}

void UITTGameInstanceBase::InitializeGameManagers()
{
}

void UITTGameInstanceBase::TickGameManagers(float DeltaSeconds)
{
}

void UITTGameInstanceBase::DestroyGameManagers()
{
}

bool UITTGameInstanceBase::RegisterTick()
{
	TickDelegateHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UITTGameInstanceBase::Tick));
	return true;
}

void UITTGameInstanceBase::UnregisterTick()
{
	FTSTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
}
// ==================================== //