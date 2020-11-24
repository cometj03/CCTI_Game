#include "stdafx.h"
#include "StartButton.h"
#include "GameScene.h"

StartButton::StartButton(const wchar_t* uri)
	:Button(uri)
{
}

void StartButton::OnClick()
{
	std::cout << "Start\n";
	Scene::ChangeScene(new GameScene());
}
