// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonTextBlock.h"
#include "ITTTextBlock.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTTextBlock : public UCommonTextBlock
{
	GENERATED_BODY()

public:
	UITTTextBlock();

	
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void SynchronizeProperties() override;

	virtual void OnTextChanged() override;
	virtual void OnFontChanged() override;

	
public:
	// ==================== Getter / Setter ==================== //
	// ========== String Index ========== //
	UFUNCTION(Category=ITT, BlueprintCallable)
	void SetStringIndex(int32 _StringIndex);

	UFUNCTION(Category=ITT, BlueprintPure)
	int32 GetStringIndex() const { return StringIndex; }
	// ================================== //
	// ========================================================= //

	
protected:
	// ========== String Index ========== //
	void OnChangeStringIndex();
	// ================================== //

	
protected:
	// ========== String Index ========== //
    UPROPERTY(Category=ITT, EditAnywhere, BlueprintGetter=GetStringIndex, BlueprintSetter=SetStringIndex)
	int32 StringIndex;
	// ================================== //
};
//ToDo : Editor View에서 적용값을 볼 수 있도록 개발