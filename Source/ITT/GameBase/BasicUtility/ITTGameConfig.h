// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ITTGameConfig.generated.h"

/**
 * 
 */
UCLASS(Config=Game)
class ITT_API UITTGameConfig : public UObject
{
	GENERATED_BODY()

public:
	UITTGameConfig();
};