#pragma once
#include "RenderInfo.h"
#include "Font.h"

//FontInfo입니다.
//Font를 사용하는 GameObject의 RenderInfo로써 저장되어야 합니다.

class FontInfo :
	public RenderInfo
{
public:
	FontInfo(Font* font = nullptr);
	Font* font;

	//출력을 위한 text값을 저장합니다.
	std::wstring text;

	//출력할 텍스트의 크기를 지정합니다.
	//기본적으로는 0.0f에 overflow로 지정되어있습니다. 필요에 따라 Font 오브젝트의 요소를 변경하여 사용 가능합니다.
	D2D1_RECT_F textRect;

	//RenderInfo의 Render를 상속받아 사용합니다.
	virtual void Render(D2DApp* d2dApp, Transform* transform, Vector2 screenPosition);
	void FontRender(ID2D1RenderTarget* renderTarget, Transform* transform,  D2D1_RECT_F* sourceRect, Vector2 screenPosition);
};

