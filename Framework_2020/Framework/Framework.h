#pragma once
#include "WinApp.h"
#include "D2DApp.h"
#include "Scene.h"

//게임의 모든 것을 나타내는 Framework입니다.
//여러 라이브러리를 초기화하고, 게임 루프를 돌립니다.
class Framework
{
public:
	Framework();
	~Framework();
private:
	WinApp* winApp;
	D2DApp* d2dApp;

public:
	//main 함수에서 호출되는 함수입니다.
	void Run(Scene* startScene,const wchar_t* title, int width, int height, bool isFullScreen);

private:
	//게임 루프를 실행합니다.
	void StartGameLoop();
};
