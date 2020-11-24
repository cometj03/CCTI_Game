#include "stdafx.h"
#include "EndToMain.h"
#include "StartScene.h"
#include "InputManager.h"

//화면을 클릭하면 메인 화면으로 이동합니다.

void EndToMain::Update()
{
	if (InputManager::GetKeyDown(VK_RETURN))
	{
		Scene::ChangeScene(new StartScene());
	}
	if (InputManager::GetKeyDown(VK_ESCAPE))
	{
		Scene::ChangeScene(new StartScene());
	}
}
