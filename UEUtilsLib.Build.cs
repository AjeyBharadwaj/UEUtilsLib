// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEUtilsLib : ModuleRules
{
	public UEUtilsLib(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core"});
	}
}
