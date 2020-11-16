#pragma once
#include "GameObject.h"
#include "FontInfo.h"
class FontObject :
	public GameObject
{
public:
	FontObject();
	~FontObject();

	void Update();

	float timer;

	Font* font;						//자세한 설명은 Font.h 참고
	FontInfo* fontRenderer;		//자세한 설명은 FontRenderer.h 참고
	std::wstring ws;
};

