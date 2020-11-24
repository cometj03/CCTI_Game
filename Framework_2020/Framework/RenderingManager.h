#pragma once
#include "stdafx.h"
#include "D2DApp.h"
#include "RenderInfo.h"

//렌더링을 관리하는 클래스입니다.
//매 Scene에 하나씩 생성됩니다.
//D2DApp과 RenderInfo(Renderer)와의 소통창구 역할을 합니다.

class RenderingManager
{
private:
	//D2DApp 클래스를 받아옵니다.
	D2DApp* d2dApp;

	//화면 크기를 저장합니다.
	Vector2 screenSize;

public:
	RenderingManager(D2DApp* d2dApp);
	~RenderingManager();

public:
	//Scene에서 사용할 Sprite를 한 곳에 모아 저장합니다.
	//여러 Sprite를 Load할 경우 이 리스트에 이미 Sprite가 있다면 그 Sprite를 사용합니다.
	std::list<Sprite*> spriteList;

	//png, jpg, bmp, gif 등의 파일을 로드합니다.
	//Direct2D에서 출력하기 위하여 비트맵 형식으로 변환하여 저장됩니다.
	Sprite* LoadBitmapFromFile(PCWSTR uri, UINT destinationWidth, UINT destinationHeight);

	//Font를 출력하기 위한 함수입니다.
	//Font 객체 내에서 사용합니다.
	IDWriteTextFormat* CreateTextFormat(const WCHAR* fontFamilyName, IDWriteFontCollection* fontCollection, DWRITE_FONT_WEIGHT fontWeight, DWRITE_FONT_STYLE fontStyle, DWRITE_FONT_STRETCH fontStretch, FLOAT fontSize, const WCHAR* localeName);
	ID2D1SolidColorBrush* CreateSolidColorBrush(const D2D1_COLOR_F& color);

	//Scene->Render에서 사용합니다.
	//Render의 시작과 끝에 호출됩니다.
	void BeginRender();
	void EndRender();	
};

