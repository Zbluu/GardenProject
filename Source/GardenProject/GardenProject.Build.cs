// Copyright Alexandre Depail. All Rights Reserved.

using UnrealBuildTool;

public class GardenProject : ModuleRules
{
	public GardenProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
