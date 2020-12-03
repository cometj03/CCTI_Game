#pragma once
#include "Button.h"

class EndButton : public Button
{
public:
	EndButton(const wchar_t* uri, int id);

	int id;

	void OnClick();
	void OnMouseHover();
	void OnMouseExit();
};

