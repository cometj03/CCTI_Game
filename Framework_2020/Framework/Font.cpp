#include "stdafx.h"
#include "Font.h"
#include "Framework.h"

Font::Font(const wchar_t* fontName, float fontSize, float red, float green, float blue, float alpha, bool isBold)
	:fontWeight(DWRITE_FONT_WEIGHT_NORMAL), fontSize(fontSize), fontName(fontName), fontStretch(DWRITE_FONT_STRETCH_NORMAL),
	fontStyle(DWRITE_FONT_STYLE_NORMAL), textFormat(nullptr), colorBrush(nullptr)
{
	CreateFontStyle(fontName, fontSize, red, green, blue, alpha, isBold);
}

Font::~Font()
{
	SAFE_RELEASE(textFormat);
	SAFE_RELEASE(colorBrush);
}

void Font::CreateFontStyle(const wchar_t* fontName, float fontSize, float red, float green, float blue, float alpha, bool isBold)
{
	if (isBold)
		fontWeight = DWRITE_FONT_WEIGHT_BOLD;
	textFormat = Scene::GetCurrentScene()->GetRenderingManager()->CreateTextFormat(
		fontName,
		NULL,
		fontWeight,
		fontStyle,
		fontStretch,
		fontSize,
		L""
	);
	if (!textFormat)
		printf("폰트 생성 실패\n");
	textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	textFormat->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
	textFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	D2D1::ColorF color(red, green, blue, alpha);
	colorBrush
		= Scene::GetCurrentScene()->GetRenderingManager()->CreateSolidColorBrush(color);
	if (!colorBrush)
		printf("색상값 조정 실패\n");
}

void Font::UpdateFontStyle(const wchar_t* fontName, float fontSize, float red, float green, float blue, float alpha, bool isBold)
{
	SAFE_RELEASE(textFormat);
	SAFE_RELEASE(colorBrush);
	CreateFontStyle(fontName, fontSize, red, green, blue, alpha, isBold);
}

const wchar_t* Font::GetFontName()
{
	return fontName;
}

DWRITE_FONT_WEIGHT Font::GetFontWeight()
{
	return fontWeight;
}


DWRITE_FONT_STYLE Font::GetFontStyle()
{
	return fontStyle;
}

DWRITE_FONT_STRETCH Font::GetFontStretch()
{
	return fontStretch;
}

float Font::GetFontSize()
{
	return fontSize;
}

IDWriteTextFormat* Font::GetTextFormat()
{
	return textFormat;
}

ID2D1SolidColorBrush* Font::GetColorBrush()
{
	return colorBrush;
}
