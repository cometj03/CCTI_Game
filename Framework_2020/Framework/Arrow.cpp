#include "stdafx.h"
#include "Arrow.h"
#include "InputManager.h"

Arrow::Arrow() 
	: GameObject(L"resources/image/arrow_1.png"), state(eArrow::Right), posVec(Vector2(0, -1))
{
}

Arrow::~Arrow()
{
}

void Arrow::Update()
{
	Move();
}

void Arrow::Move()
{
	if (InputManager::GetKeyDown(VK_UP))
	{
		posVec.y += posVec.y < 0 ? 1 : 0;
	}
	if (InputManager::GetKeyDown(VK_DOWN))
	{
		posVec.y -= posVec.y > limitPos.y ? 1 : 0;
	}
	if (InputManager::GetKeyDown(VK_RIGHT))
	{
		posVec.x += posVec.x < limitPos.x ? 1 : 0;
	}
	if (InputManager::GetKeyDown(VK_LEFT))
	{
		posVec.x -= posVec.x > 0 ? 1 : 0;
	}

	transform->SetPosition(posVec * 75 + offset);
}