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
	std::vector<SheetAnimation*> coinAnimList;

	virtual void Update();
	void SwitchCoin();
};

