#include "stdafx.h"
#include "OverScene.h"

OverScene::OverScene()
{
}

OverScene::~OverScene()
{
}

void OverScene::Initialize()
{
	Push(new GameObject(L"resources/image/clear_panel.png"));
	GameObject* home = PushUI(new GameObject(L"resources/image/ui_home.png"));
	GameObject* again = PushUI(new GameObject(L"resources/image/ui_again.png"));
	home->transform->SetPosition(250, 400);
	again->transform->SetPosition(550, 400);
}
