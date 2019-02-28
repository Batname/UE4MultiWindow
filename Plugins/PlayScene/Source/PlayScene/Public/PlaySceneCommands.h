// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "PlaySceneStyle.h"

class FPlaySceneCommands : public TCommands<FPlaySceneCommands>
{
public:

	FPlaySceneCommands()
		: TCommands<FPlaySceneCommands>(TEXT("PlayScene"), NSLOCTEXT("Contexts", "PlayScene", "PlayScene Plugin"), NAME_None, FPlaySceneStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};