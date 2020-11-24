#include "stdafx.h"
#include "StartScene.h"
#include "StartButton.h"
#include "ExitButton.h"

void StartScene::Initialize()
{
	Push(new GameObject(L"resources/background.png"));
	GameObject* start = PushUI(new StartButton(L"resources/PlayButton.png"));
	start->transform->SetPosition(200.0f, 450.0f);
	start->transform->SetScale(0.3f, 0.3f);

	GameObject* end = PushUI(new ExitButton(L"resources/ExitButton.png"));
	end->transform->SetPosition(600.0f, 450.0f);
	end->transform->SetScale(0.3f, 0.3f);

	GameObject* title = PushUI(new GameObject(L"resources/SimpleLogo.png"));
	title->transform->SetPosition(400.0f, 150.0f);
}
