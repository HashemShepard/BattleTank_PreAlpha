// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BT_Pre_AlphaEditorTarget : TargetRules
{
	public BT_Pre_AlphaEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "BT_Pre_Alpha" } );
	}
}
