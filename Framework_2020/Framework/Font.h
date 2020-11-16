#pragma once
#include "stdafx.h"

//글씨를 나타낼 오브젝트의 속성을 지정합니다.
//기본적으로 폰트 이름, 폰트 크기, 색상, 굵기 등을 지정합니다.
//DWRITE_FONT_XXXX 형태의 변수는 enum(열거형)형태이고, 구글링을 해보시면 많은 옵션을 찾을 수 있습니다. 세부적인 수치 조정이 가능하니 참고하세요.

class Font
{
	friend class FontInfo;
public:
	Font(const wchar_t* fontName, float fontSize = 20.0f, float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f, bool isBold = false);
	virtual ~Font();
private:
	const wchar_t* fontName;		//폰트명
	DWRITE_FONT_WEIGHT fontWeight;	//폰트 굵기
	DWRITE_FONT_STYLE fontStyle;	//폰트 스타일
	DWRITE_FONT_STRETCH fontStretch;//글자 길이 조절
	float fontSize;
	IDWriteTextFormat* textFormat;	//실제 dwrite 텍스트 포맷
	ID2D1SolidColorBrush* colorBrush;
public:
	void CreateFontStyle(const wchar_t* fontName, float fontSize = 20.0f, float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f, bool isBold = false);
	void UpdateFontStyle(const wchar_t* fontName, float fontSize = 20.0f, float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f, bool isBold = false);

	const wchar_t* GetFontName();		//폰트명
	DWRITE_FONT_WEIGHT GetFontWeight();	//폰트 굵기
	DWRITE_FONT_STYLE GetFontStyle();	//폰트 스타일
	DWRITE_FONT_STRETCH GetFontStretch();//글자 길이 조절
	float GetFontSize();
	IDWriteTextFormat* GetTextFormat();	//실제 dwrite 텍스트 포맷
	ID2D1SolidColorBrush* GetColorBrush();

};

