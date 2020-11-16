#include "stdafx.h"
#include "FontObject.h"
#include "TimeManager.h"

FontObject::FontObject()
	:GameObject(fontRenderer = new FontInfo())
{
	ws = L"셋을 세세요.";
	timer = 0.0f;
	font = new Font(L"돋움",20.0f,1.0f,1.0f,1.0f);						//폰트, 색상 등을 지니는 Font 클래스 생성(Font.h 참고), 기본 크기 20pt
	fontRenderer->font = this->font;				//텍스트의 속성을 지정해줍니다.

	fontRenderer->text = ws;						//텍스트의 내용을 지정해줍니다.
	transform->SetPosition(0.0f,0.0f);			//위치 지정
	//transform->SetRotation(30.0f);					//각도 지정
	transform->SetScale(1.0f, 1.0f);				//크기 지정 모두 가능합니다.
}

FontObject::~FontObject()
{
	SAFE_DELETE(font);
}

void FontObject::Update()
{
	timer += TimeManager::GetDeltaTime();
	if (timer > 3.0f)
	{
		fontRenderer->font->UpdateFontStyle(L"궁서",24.0f,1.0f,0.0f,0.0f,0.5f,true);
		fontRenderer->text = L"Enter키를 누르면 넘어갑니다.\n아니면 여기를 클릭하세요.";
		std::wcout << fontRenderer->text;
	}
}
