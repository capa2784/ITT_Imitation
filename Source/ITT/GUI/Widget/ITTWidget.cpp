// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTWidget.h"

#include "GameBase/GameManager/ITTWidgetManager.h"


UITTWidget::UITTWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), bManaged(true), WidgetKey(FName()), bActive(false), bAddToViewport(false)
	, VisibilityOnActivate(ESlateVisibility::SelfHitTestInvisible), ZOrder(0)
{
}


void UITTWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UITTWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UITTWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UITTWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UITTWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UITTWidget::BuiltInInitialize(bool _bManaged, const FName& _WidgetKey, int32 _ZOrder)
{
	bManaged = _bManaged;
	WidgetKey = _WidgetKey;
	ZOrder = _ZOrder;
}


// ========== View ========== //
void UITTWidget::ChangeActivation(bool _bActivate)
{
	if (bActive != _bActivate)
	{
		bActive = _bActivate;

		if (bActive)
		{
			Activate_Internal();
		}
		else
		{
			Deactive_Internal();
		}
	}
}

void UITTWidget::Activate_Internal()
{
	if (!bAddToViewport)
	{
		bAddToViewport = true;
		AddToViewport(ZOrder);
	}

	if (!IsVisible())
	{
		SetVisibility(VisibilityOnActivate);
	}
}

void UITTWidget::Deactive_Internal()
{
	if (bAddToViewport)
	{
		SetVisibility(ESlateVisibility::Hidden);
	}
}
// ========================== //


// ========== Close ========== //
void UITTWidget::ITTCloseWidget(bool bImmediately)
{
	bool bSuccessToAsk = false;
	
	if (bManaged)
	{
		UITTWidgetManager* WidgetManager = UITTWidgetManager::GetInstance();
		ITTCHECK(WidgetManager);
		
		bSuccessToAsk = WidgetManager->ITTDestroyWidget(WidgetKey, bImmediately);
	}

	if (!bSuccessToAsk)
	{
		AskToFinish(bImmediately);
	}
}

void UITTWidget::AskToFinish(bool bImmediately)
{
	OnReadyToFinishDelegate = FITTOnReadyToFinishDelegate::CreateUObject(this, &UITTWidget::Finish);

	if (bImmediately)
	{
		PrepareToFinish_Immediately();
	}
	else
	{
		PrepareToFinish();
	}
}

void UITTWidget::PrepareToFinish()
{
	bool bDelegateBound = OnReadyToFinishDelegate.ExecuteIfBound();	// Call UITTWidget::Finish()
	if (!bDelegateBound)
	{
		ITTLOG(Error, TEXT("[%s] OnReadyToFinishDelegate isn't bound [WidgetKey : %s]")
			, *ITTSTRING_CLASS_FUNC, *WidgetKey.ToString());
	}
}

void UITTWidget::PrepareToFinish_Immediately()
{
	bool bDelegateBound = OnReadyToFinishDelegate.ExecuteIfBound();	// Call UITTWidget::Finish()
	if (!bDelegateBound)
	{
		ITTLOG(Error, TEXT("[%s] OnReadyToFinishDelegate isn't bound [WidgetKey : %s]")
			, *ITTSTRING_CLASS_FUNC, *WidgetKey.ToString());
	}
}

void UITTWidget::Finish()
{
	bAddToViewport = false;
	bActive = false;
	
	Deactive_Internal();

	if (IsValidLowLevel())
	{
		RemoveFromParent();
	}
}
// =========================== //