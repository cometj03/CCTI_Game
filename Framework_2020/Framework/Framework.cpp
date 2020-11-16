#include "stdafx.h"
#include "Framework.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Random.h"
#include "Audio.h"

Framework::Framework()
{
	winApp = new WinApp();
	d2dApp = new D2DApp(winApp);
}

Framework::~Framework()
{
	SAFE_DELETE(winApp);
	SAFE_DELETE(d2dApp);
}

void Framework::Run(Scene* startScene, const wchar_t* title, int width, int height, bool isFullScreen)
{
	Random::GetInstance();
	if (SUCCEEDED(CoInitialize(NULL)))
	{
		if (winApp->Initialize(title, width, height, isFullScreen))
		{
			if (d2dApp->Initialize())
			{
				bool audioInitialized = Audio::GetInstance()->Initialize();
				InputManager::winApp = winApp;
				Scene::ChangeScene(startScene);
				Scene::SwapScene(d2dApp);
				StartGameLoop();
				SAFE_DELETE(Scene::currentScene);
				SAFE_DELETE(Scene::nextScene);
				if (audioInitialized)
					Audio::GetInstance()->Uninitialize();
				d2dApp->Uninitialize();
			}
		}
		CoUninitialize();
	}
}

void Framework::StartGameLoop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//Check Input
		TimeManager::UpdateTime();
		InputManager::UpdateKeyState();
		//Update World
		Scene::currentScene->UpdateGameObjects();
		Scene::currentScene->UpdatePhysics();
		Scene::currentScene->DeleteDestroyedObjects();
		Scene::currentScene->Render();
		//Change Scene
		Scene::SwapScene(d2dApp);
	}
}