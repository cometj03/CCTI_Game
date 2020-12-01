#include "stdafx.h"
#include "Arrow.h"
#include "InputManager.h"

Arrow::Arrow(AnimationInfo* animInfo) 
	: GameObject(animInfo), state(eArrow::Right), posVec(Vector2(0, -1))
{
	this->animRenderer = animInfo;

	for (int i = 0; i < 4; i++)
		animList[i] = new ListAnimation(i, 1.0f);	// state : 0~3, 초당 1프레임
	
	animList[0]->PushBackSprite(L"resources/image/arrow_R.png");
	animList[1]->PushBackSprite(L"resources/image/arrow_D.png");
	animList[2]->PushBackSprite(L"resources/image/arrow_RD.png");
	animList[3]->PushBackSprite(L"resources/image/arrow_RU.png");

	for (int i = 0; i < 4; i++)
		animRenderer->PushBackAnimation(animList[i]);

}

Arrow::~Arrow()
{
}

void Arrow::Update()
{
	Move();
	ChangeSprite();
}

void Arrow::Move()
{
	if (InputManager::GetKeyDown(VK_UP))
	{
		posVec.y += posVec.y < 0 ? 1 : 0;
	}
	if (InputManager::GetKeyDown(VK_DOWN))
	{
		posVec.x = 0;
		posVec.y -= posVec.y > limitPos.y ? 1 : 0;
	}
	if (InputManager::GetKeyDown(VK_RIGHT))
	{
		posVec.y = 0;
		posVec.x += posVec.x < limitPos.x ? 1 : 0;
	}
	if (InputManager::GetKeyDown(VK_LEFT))
	{
		posVec.x -= posVec.x > 0 ? 1 : 0;
	}

	transform->SetPosition(posVec * 75 + offset);
}

void Arrow::ChangeSprite()
{
	if (posVec.x == 0) {
		if (posVec.y == 0)
			state = eArrow::RD;
		else if (posVec.y == limitPos.y)
			state = eArrow::RU;
		else
			state = eArrow::Right;
	}
	else {
		state = eArrow::Down;
	}

	switch (state)
	{
	case eArrow::Right:
		animRenderer->ChangeAnimation(0);
		break;
	case eArrow::Down:
		animRenderer->ChangeAnimation(1);
		break;
	case eArrow::RD:
		animRenderer->ChangeAnimation(2);
		break;
	case eArrow::RU:
		animRenderer->ChangeAnimation(3);
		break;
	default:
		break;
	}
}