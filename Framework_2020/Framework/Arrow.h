#pragma once
#include "GameObject.h"
#include "AnimationInfo.h"
#include "ListAnimation.h"

#include <list>

enum class eArrow {
	Right, Down, RD, RU
};

class Arrow : public GameObject
{
public:
	Arrow(AnimationInfo* animinfo);
	~Arrow();

	eArrow state;
	Vector2 posVec;
	const Vector2 limitPos = Vector2(3, -4);
	const Vector2 offset = Vector2(-150, 150);

	AnimationInfo* animRenderer;
	ListAnimation* animList[];

	virtual void Update();
	void Move();
	void ChangeSprite();

	// TODO: 화살표 위치에 따라서 코인 뒤집기
};

