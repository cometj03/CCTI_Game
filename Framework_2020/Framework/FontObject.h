#pragma once
#include "GameObject.h"
#include "FontInfo.h"

//폰트를 사용하는 오브젝트의 예시 오브젝트 입니다.
//예시 오브젝트지만, 실제 게임에서는 TextObject 사용을 권장합니다.

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

