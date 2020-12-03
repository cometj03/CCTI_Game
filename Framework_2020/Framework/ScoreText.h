#pragma once
#include "TextObject.h"

class ScoreText : public TextObject
{
public:
	ScoreText(const wchar_t* text);
	ScoreText(std::wstring text);
	~ScoreText();

	void UpdateScore();
};

