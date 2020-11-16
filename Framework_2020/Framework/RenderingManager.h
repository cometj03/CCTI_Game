#pragma once
#include "stdafx.h"
#include "D2DApp.h"
#include "RenderInfo.h"

class RenderingManager
{
private:
	D2DApp* d2dApp;
	Vector2 screenSize;
public:
	RenderingManager(D2DApp* d2dApp);
	~RenderingManager();
public:
	std::list<Sprite*> spriteList;
	Sprite* LoadBitmapFromFile(PCWSTR uri, UINT destinationWidth, UINT destinationHeight);
	IDWriteTextFormat* CreateTextFormat(const WCHAR* fontFamilyName, IDWriteFontCollection* fontCollection, DWRITE_FONT_WEIGHT fontWeight, DWRITE_FONT_STYLE fontStyle, DWRITE_FONT_STRETCH fontStretch, FLOAT fontSize, const WCHAR* localeName);
	ID2D1SolidColorBrush* CreateSolidColorBrush(const D2D1_COLOR_F& color);

	//Scene->Render에서 사용
	void BeginRender();
	void EndRender();	
};

