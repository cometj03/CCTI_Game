#pragma once
#include "GameObject.h"
#include "AnimationInfo.h"
#include "SheetAnimation.h"

class Coin : public GameObject
{
public:
	Coin(AnimationInfo* animInfo);
	~Coin();

	AnimationInfo* animRenderer;
	SheetAnimation* coinAnimList[];	// TODO: 애니메이션 한번만 실행되게 바꾸기

	virtual void Update();
	void SwitchCoin();
};

