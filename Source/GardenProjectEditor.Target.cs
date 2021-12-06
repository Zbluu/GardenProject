// Copyright Alexandre Depail. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GardenProjectEditorTarget : TargetRules
{
	public GardenProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GardenProject");
	}
}
