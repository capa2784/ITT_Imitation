// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


// ==================== Define ==================== //
// ========== Log / Assert ========== //
DECLARE_LOG_CATEGORY_EXTERN(ITTLog, Log, All);
#define ITTLOG(Verbosity, Msg, ...) UE_LOG(ITTLog, Verbosity, Msg, ##__VA_ARGS__)

#define ITTCHECK(Expr) check(Expr)
#define ITTCHECKF(Expr, Msg, ...) checkf(Expr, Msg, ##__VA_ARGS__)
#define ITTENSURE(Expr) ensure(Expr)
#define ITTENSUREF(Expr, Msg, ...) ensureMsgf(Expr, Msg, ##__VA_ARGS__)

#define ITTTEXT_CLASS_FUNC __FUNCTION__
#define ITTSTRING_CLASS_FUNC FString(__FUNCTION__)
// ================================== //
// ================================================ //


// ==================== Function ==================== //
// ========== Object ========== //
#define ITTNewObject NewObject

#define ITTDeleteObject(Object) { \
if (Object == nullptr) return; \
if (!Object->IsValidLowLevel()) return; \
Object->ConditionalBeginDestroy(); \
Object = nullptr; \
};
// ============================ //
// ================================================== //