// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ManeuverGear : ModuleRules
{
	public ManeuverGear(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "CableComponent" });
	}
}
