#pragma once
#include "GameObject.h"
#include "FontInfo.h"

//Text만을 사용할 때 쓰면 편한 오브젝트입니다.
//Font정보와 font Renderer를 가지고 있습니다.

class TextObject :
	public GameObject
{
public:
	//TextObject를 생성하고, 생성자에 문자열을 넣어주면 해당 텍스트 생성이 가능합니다.
	//이후에는 textObject->fontRenderer->text 값을 수정하여 문자열 수정이 가능합니다.
	TextObject(const wchar_t* text);
	TextObject(std::wstring text);
	~TextObject();

	Font* font;						//자세한 설명은 Font.h 참고
	FontInfo* fontRenderer;		//자세한 설명은 FontRenderer.h 참고
};