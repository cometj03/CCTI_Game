#pragma once
#include "Button.h"

class PlayButton : public Button
{
public:
	PlayButton(const wchar_t* uri); 

	void OnClick();
	void OnMouseHover();
	void OnMouseExit();
};

