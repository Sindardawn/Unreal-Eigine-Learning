// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShootIt : ModuleRules
{
	public ShootIt(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
