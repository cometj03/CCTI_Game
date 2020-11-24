#include "stdafx.h"
#include "Button.h"
#include "InputManager.h"

Button::Button(const wchar_t* uri) :
	GameObject(uri)
{
	col = new AABBCollider(this, renderer);
}

Button::~Button()
{
	SAFE_DELETE(col);
}

void Button::Update()
{
	if (col->isMouseOnUI() && InputManager::GetKeyDown(VK_LBUTTON))
	{
		OnClick();
	}
}
