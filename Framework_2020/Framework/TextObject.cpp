#include "stdafx.h"
#include "TextObject.h"

TextObject::TextObject(const wchar_t* text)
	:GameObject(fontRenderer = new FontInfo())
{
	font = new Font(L"돋움", 20.0f, 1.0f, 1.0f, 1.0f);	//폰트, 색상 등을 지니는 Font 클래스 생성(Font.h 참고), 기본 크기 20pt
	fontRenderer->font = this->font;					//텍스트의 속성을 지정해줍니다.
	fontRenderer->text = std::wstring(text);
}

TextObject::TextObject(std::wstring text)
	:GameObject(fontRenderer = new FontInfo())
{
	font = new Font(L"돋움", 20.0f, 1.0f, 1.0f, 1.0f);	//폰트, 색상 등을 지니는 Font 클래스 생성(Font.h 참고), 기본 크기 20pt
	fontRenderer->font = this->font;					//텍스트의 속성을 지정해줍니다.
	fontRenderer->text = text;
}

TextObject::~TextObject()
{
	SAFE_DELETE(font);
}
