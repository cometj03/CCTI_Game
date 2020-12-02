#pragma once
#include "GameObject.h"
#include "AnimationInfo.h"
#include "ListAnimation.h"
#include "Coin.h"

enum class eArrow {
	Right, Down, RD, RU
};

static const Vector2 limitPos = Vector2(3, -4);
static const Vector2 offset = Vector2(-150, 150);

class Arrow : public GameObject
{
public:
	Arrow(AnimationInfo* animinfo);
	~Arrow();

	eArrow state;
	Vector2 posVec;

	AnimationInfo* animRenderer;
	std::vector<ListAnimation*> arrowShape;

	virtual void Update();
	void Move();
	void ChangeSprite();
	void SwitchCoins();
	// TODO: 리스트 전송하는 함수

	std::vector<Coin*> coins;
	void PutCoins(std::vector<Coin*> c);
};

