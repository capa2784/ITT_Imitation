// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTTable_Scene.h"

#include "ITTUtilityFunctionLibrary.h"


UITTTable_Scene::UITTTable_Scene()
{
}


void UITTTable_Scene::Initialize()
{
	Super::Initialize();

	ITTCHECK(GetDataTable());

	EntireSceneTypes.Empty();
	SceneClasses.Empty();
	SceneLevelNames.Empty();
	
	TArray<FITTTableRow_Scene*> Rows;
	GetDataTable()->GetAllRows<FITTTableRow_Scene>(ITTTEXT_CLASS_FUNC, Rows);

	for (FITTTableRow_Scene* Row : Rows)
	{
		if (EntireSceneTypes.Contains(Row->SceneType))
		{
			FString SceneTypeName = UITTUtilityFunctionLibrary::ConvertEnumToString(TEXT("EITTSceneType"), Row->SceneType);
			ITTENSUREF(false, TEXT("[%s] The same SceneType already contained [SceneType : %s]")
				, *ITTSTRING_CLASS_FUNC, *SceneTypeName);
		}
		
		EntireSceneTypes.Emplace(Row->SceneType);
		
		SceneClasses.Emplace(Row->SceneType, Row->ITTSceneClass);
		
		SceneLevelNames.Emplace(Row->SceneType, Row->LevelName);
	}
}


// ========== Scene ========== //
TSubclassOf<UITTSceneBase> UITTTable_Scene::GetSceneClass(EITTSceneType SceneType)
{
	ITTCHECK(GetDataTable());

	if (!SceneClasses.Contains(SceneType))
	{
		FString SceneTypeName = UITTUtilityFunctionLibrary::ConvertEnumToString(TEXT("EITTSceneType"), static_cast<uint32>(SceneType));
		ITTLOG(Error, TEXT("[%s] SceneType doesn't exist in SceneClasses [SceneType : %s]"), *ITTSTRING_CLASS_FUNC, *SceneTypeName);
		return nullptr;
	}
	
	return *SceneClasses.Find(SceneType);
}

FName UITTTable_Scene::GetSceneLevelName(EITTSceneType SceneType)
{
	ITTCHECK(GetDataTable());

	if (!SceneLevelNames.Contains(SceneType))
	{
		FString SceneTypeName = UITTUtilityFunctionLibrary::ConvertEnumToString(TEXT("EITTSceneType"), static_cast<uint32>(SceneType));
		ITTLOG(Error, TEXT("[%s] SceneType doesn't exist in SceneLevelNames [SceneType : %s]"), *ITTSTRING_CLASS_FUNC, *SceneTypeName);
		return FName();
	}
	
	return *SceneLevelNames.Find(SceneType);
}
// =========================== //