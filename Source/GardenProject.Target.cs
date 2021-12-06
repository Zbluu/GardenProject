// Copyright Alexandre Depail. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GardenProjectTarget : TargetRules
{
	public GardenProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GardenProject");
	}
}
