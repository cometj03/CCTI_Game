#pragma once
#include "RenderInfo.h"
#include "Font.h"
class FontInfo :
	public RenderInfo
{
public:
	FontInfo(Font* font = nullptr);
	Font* font;
	//wchar_t* text;
	std::wstring text;
	D2D1_RECT_F textRect;
	virtual void Render(D2DApp* d2dApp, Transform* transform, Vector2 screenPosition);
	void FontRender(ID2D1RenderTarget* renderTarget, Transform* transform,  D2D1_RECT_F* sourceRect, Vector2 screenPosition);
};

