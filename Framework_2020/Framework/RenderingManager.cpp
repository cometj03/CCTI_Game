#include "stdafx.h"
#include "RenderingManager.h"
#include "Framework.h"


RenderingManager::RenderingManager(D2DApp* d2dApp) :d2dApp(d2dApp)
{
}

RenderingManager::~RenderingManager()
{
	for (auto& i : spriteList)
	{
		SAFE_RELEASE(i->bitmap);
		SAFE_DELETE(i);
	}
	spriteList.clear();
}

Sprite* RenderingManager::LoadBitmapFromFile(PCWSTR uri, UINT destinationWidth, UINT destinationHeight)
{
	Sprite* sprite = nullptr;

	for (auto& i : spriteList)
	{
		if (wcscmp(i->uri, uri) == 0)
			return i;
	}
	sprite = new Sprite();
	if (SUCCEEDED(d2dApp->LoadBitmapFromFile(uri, 0, 0, &sprite->bitmap)))
	{
		sprite->uri = uri;
		spriteList.push_back(sprite);
		return sprite;
	}
	else 
	{
		SAFE_DELETE(sprite);
		printf("이미지 로드 오류 발생\n");
		return nullptr;
	}
}

IDWriteTextFormat* RenderingManager::CreateTextFormat(const WCHAR* fontFamilyName, IDWriteFontCollection* fontCollection, DWRITE_FONT_WEIGHT fontWeight, DWRITE_FONT_STYLE fontStyle, DWRITE_FONT_STRETCH fontStretch, FLOAT fontSize, const WCHAR* localeName)
{
	IDWriteTextFormat* temp = nullptr;
	HRESULT hr = d2dApp->GetDwriteFactory()->CreateTextFormat(
		fontFamilyName,
		NULL,
		fontWeight,
		fontStyle,
		fontStretch,
		fontSize,
		L"",
		&temp
	);

	if (SUCCEEDED(hr))
		return temp;
	else
		return nullptr;
}

ID2D1SolidColorBrush* RenderingManager::CreateSolidColorBrush(const D2D1_COLOR_F& color)
{
	ID2D1SolidColorBrush* temp;
	HRESULT hr = d2dApp->GetRenderTarget()->CreateSolidColorBrush(
		color,
		&temp
	);

	if (SUCCEEDED(hr))
		return temp;
	else
		return nullptr;
}

void RenderingManager::BeginRender()
{
	screenSize.x = WinApp::GetScreenWidthF();
	screenSize.y = WinApp::GetScreenHeightF();
	d2dApp->BeginRender();
}

void RenderingManager::EndRender()
{
	d2dApp->EndRender();
}
