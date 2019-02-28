// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "PlayScene.h"
#include "PlaySceneStyle.h"
#include "PlaySceneCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "PlaySceneSlate.h"

#define LOCTEXT_NAMESPACE "FPlaySceneModule"

void FPlaySceneModule::StartupModule()
{
	// Initialize play button ui style
	FPlaySceneStyle::Initialize();
	FPlaySceneStyle::ReloadTextures();

	// Register play capture commands
	FPlaySceneCommands::Register();
	PluginCommands = MakeShareable(new FUICommandList);

	// Add play capture button command
	PluginCommands->MapAction(
		FPlaySceneCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FPlaySceneModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		
	// Add play capture button to editor
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FPlaySceneModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void FPlaySceneModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FPlaySceneStyle::Shutdown();

	FPlaySceneCommands::Unregister();

	// Disable PlayScene Window
	FPlaySceneSlate::Shutdown();
}

TWeakObjectPtr<UTextureRenderTarget2D> FPlaySceneModule::GetTextureRenderTarget2D()
{
	return TextureRenderTarget2D;
}

void FPlaySceneModule::SetTextureRenderTarget2D(UTextureRenderTarget2D * TexRenderTarget2D)
{
	TextureRenderTarget2D = TexRenderTarget2D;
}


void FPlaySceneModule::PluginButtonClicked()
{
	// Init layCapture Window
	FPlaySceneSlate::Initialize();
}

void FPlaySceneModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FPlaySceneCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPlaySceneModule, PlayScene)