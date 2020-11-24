#pragma once
#include "stdafx.h"

//윈도우 생성을 위한 클래스입니다.
class WinApp
{
public:
	WinApp();
private:
	//윈도우 핸들
	HWND hWnd;
	
	//가로, 세로
	static int width;
	static int height;
	static float widthF;
	static float heightF;

	//창모드 여부
	bool isFullScreen;
public:
	//윈도우 핸들 값을 받아옵니다.
	HWND GetHWND();

	//화면의 가로,세로를 받아옵니다.
	static int GetScreenWidth();
	static int GetScreenHeight();
	static float GetScreenWidthF();
	static float GetScreenHeightF();

	//창보드 여부를 받아옵니다.
	bool GetFullScreened();
public:
	//Window를 초기화합니다.
	//창을 띄우고, 화면 비를 설정하는 등의 역할을 합니다.
	bool Initialize(const wchar_t* title, int width, int height, bool isFullScreen);

	
public:
	//윈도우 프로시저 함수입니다.
	//윈도우 메시지 입력에 대한 처리가 이뤄집니다.
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};

