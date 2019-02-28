// Fill out your copyright notice in the Description page of Project Settings.

#include "PCSceneCaptureComponent2D.h"
#include "IPlayScene.h"

void UPCSceneCaptureComponent2D::Activate(bool bReset)
{
	Super::Activate();
	// Assign Render texture to shared module variale
	IPlayScene::Get().SetTextureRenderTarget2D(this->TextureTarget);
}

#if WITH_EDITOR
void UPCSceneCaptureComponent2D::OnRegister()
{
	Super::OnRegister();
	// Assign Render texture to shared module variale
	IPlayScene::Get().SetTextureRenderTarget2D(this->TextureTarget);
}
#endif
