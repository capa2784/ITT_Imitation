// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ITT : ModuleRules
{
	public ITT(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivatePCHHeaderFile = "ITT.h";
    		
    	PrivateIncludePaths.Add("ITT");
    	PrivateIncludePaths.Add("ITT/Utility");
    		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
