// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GUI/Widget/ITTWidget.h"
#include "ITTWidget_Title.generated.h"

/**
 * 
 */
UCLASS()
class ITT_API UITTWidget_Title : public UITTWidget
{
	GENERATED_BODY()

public:
	static FName GetClassWidgetKey() { return FName(ClassWidgetKey); }

	
	UITTWidget_Title(const FObjectInitializer& ObjectInitializer);
	

	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	
	// ========== Widget Animation ========== //
	void StartLogoAnimation();
	// ====================================== //

	
	// ========== Button ========== //
	void BindButtons();

	
	UFUNCTION()
	void OnClickButton_LocalPlay();

	UFUNCTION()
	void OnClickButton_OnlinePlay();

	UFUNCTION()
	void OnClickButton_Option();

	UFUNCTION()
	void OnClickButton_AccessibilityOptions();

	UFUNCTION()
	void OnClickButton_Credits();

	UFUNCTION()
	void OnClickButton_Quit();
	// ============================ //
	
	
protected:
	static constexpr char ClassWidgetKey[] = "WBP_Title";

	
	// ========== Widget Animation ========== //
	bool bWAnimFinished;
	
	UPROPERTY(Transient, Meta = (BindWidgetAnim))
	class UWidgetAnimation* WAnim_Appearance;
	// ====================================== //

	
	// ========== Button ========== //
	UPROPERTY(Meta = (BindWidget))
	class UITTButton* BTN_LocalPlay;

	UPROPERTY(Meta = (BindWidget))
	class UITTButton* BTN_OnlinePlay;

	UPROPERTY(Meta = (BindWidget))
	class UITTButton* BTN_Option;

	UPROPERTY(Meta = (BindWidget))
	class UITTButton* BTN_AccessibilityOptions;

	UPROPERTY(Meta = (BindWidget))
	class UITTButton* BTN_Credits;

	UPROPERTY(Meta = (BindWidget))
	class UITTButton* BTN_Quit;
	// ============================ //
};
