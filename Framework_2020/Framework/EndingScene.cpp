#include "stdafx.h"
#include "EndingScene.h"
#include "TextObject.h"
#include "EndToMain.h"

//생성자입니다.
//score 값을 받아온 후, 점수를 계산하여 ment 문자열에 넣어둡니다.
//그 후 실제 Scene이 시작될 때, TextObject에 추가하여 사용합니다.
EndingScene::EndingScene(int score)
{
	std::wstring a = L"당신의 점수는";
	std::wstring b = L"점 입니다.";
	ment = a + std::to_wstring(score) + b;
}

EndingScene::~EndingScene()
{
}

void EndingScene::Initialize()
{
	//background를 추가합니다.
	Push(new GameObject(L"resources/background.png"));

	//엔딩 Scene에서 Esc를 누르면 메인으로 돌아가는 내용을 구현한 객체입니다.
	EndToMain* etm = new EndToMain();
	Push(etm);

	//마무리 멘트를 출력하는 객체입니다.
	TextObject* text = new TextObject(ment);
	text->transform->SetPosition(400.0f, 300.0f);
	PushUI(text);
}
