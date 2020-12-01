#pragma once
#include "GameObject.h"

enum class eArrow {
	Right, Down, RD, RU
};

class Arrow : public GameObject
{
public:
	Arrow();
	~Arrow();

	eArrow state;
	Vector2 posVec;
	const Vector2 limitPos = Vector2(3, -4);
	const Vector2 offset = Vector2(-150, 150);

	virtual void Update();
	void Move();
};

