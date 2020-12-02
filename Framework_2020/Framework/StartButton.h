#pragma once
#include "Button.h"

class StartButton : public Button
{
public:
	StartButton(const wchar_t* uri);
	void OnClick();
};

