// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "PlaySceneCommands.h"

#define LOCTEXT_NAMESPACE "FPlaySceneModule"

void FPlaySceneCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "PlayScene", "Bring up PlayScene window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
