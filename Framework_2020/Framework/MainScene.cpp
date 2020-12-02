#include "stdafx.h"
#include "MainScene.h"
#include "PlayButton.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

void MainScene::Initialize()
{
	background = Push(new GameObject(L"resources/image/background.png"));

	playButton = PushUI(new PlayButton(L"resources/image/ui_start.png"));
	playButton->transform->SetPosition(400, 360);

	logo = Push(new GameObject(L"resources/image/ui_logo.png"));
	logo->transform->SetPosition(0, 70);
	logo->transform->SetScale(1.3f, 1.3f);
}
