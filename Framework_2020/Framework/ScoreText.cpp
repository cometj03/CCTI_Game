#include "stdafx.h"
#include "ScoreText.h"
#include "GameManager.h"

ScoreText::ScoreText(const wchar_t* text) :
	TextObject(text)
{
	transform->SetPosition(400, 20);
}

ScoreText::ScoreText(std::wstring text) :
	TextObject(text)
{
	transform->SetPosition(400, 20);
}

ScoreText::~ScoreText()
{
}

void ScoreText::UpdateScore()
{
	fontRenderer->text = L"SCORE: " + std::to_wstring(GameManager::GetInstance()->score);
	if (GameManager::GetInstance()->score <= 50)
	{
		// 50Á¡ ÀÌÇÏ¸é »¡°£ ±Û¾¾
		Font* font = new Font(L"Amatic SC", 32.0f, 0.8f, 0.0f, 0.0f, 1.0f, true);
		fontRenderer->font = font;
	}
}
