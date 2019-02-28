// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UE4MultiWindowHud.generated.h"

UCLASS(config = Game)
class AUE4MultiWindowHud : public AHUD
{
	GENERATED_BODY()

public:
	AUE4MultiWindowHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface

};
