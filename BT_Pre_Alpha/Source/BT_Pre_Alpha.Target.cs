// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BT_Pre_AlphaTarget : TargetRules
{
	public BT_Pre_AlphaTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "BT_Pre_Alpha" } );
	}
}
