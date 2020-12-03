#include "stdafx.h"
#include "Button.h"
#include "InputManager.h"

Button::Button(const wchar_t* uri)
	: GameObject(uri), isHover(false)
{
	col = new AABBCollider(this, renderer);
}

Button::~Button()
{
	SAFE_DELETE(col);
}

void Button::Update()
{
	if (col->isMouseOnUI())
	{
		if (!isHover)	// Hover 함수 한번만 실행하기 위한 bool형 플래그
		{
			OnMouseHover();	
			isHover = true;
		}

		if (InputManager::GetKeyDown(VK_LBUTTON))
			OnClick();
	}
	else if (isHover)
	{
		OnMouseExit();
		isHover = false;
	}
}
