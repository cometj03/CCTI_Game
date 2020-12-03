#include "stdafx.h"
#include "OverScene.h"
#include "TextObject.h"
#include "GameManager.h"

OverScene::OverScene() :
	isClear(false)
{
}

OverScene::OverScene(int score) :
	isClear(true), score(score)
{
}

OverScene::~OverScene()
{
}

void OverScene::Initialize()
{
	if (isClear)
	{
		background = new GameObject(L"resources/image/clear_panel.png");
		background->transform->SetScale(0.5f, 0.5f);
		Push(background);
		TextObject* to = new TextObject(L"YOUR SCORE : " + std::to_wstring(this->score));
		to->transform->SetPosition(400, 280);
		PushUI(to);
	}
	else
	{
		background = new GameObject(L"resources/image/lose_panel.png");
		background->transform->SetScale(0.7f, 0.7f);
		Push(background);
	}
		


	EndButton* home = (EndButton*)PushUI(new EndButton(L"resources/image/ui_home.png", 0));
	EndButton* again = (EndButton*)PushUI(new EndButton(L"resources/image/ui_again.png", 1));
	home->transform->SetPosition(330, 380);
	home->transform->SetScale(0.45f, 0.45f);
	again->transform->SetPosition(470, 380);
	again->transform->SetScale(0.45f, 0.45f);
}
