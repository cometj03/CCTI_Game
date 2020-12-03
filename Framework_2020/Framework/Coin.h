#pragma once
#include "GameObject.h"
#include "AnimationInfo.h"
#include "SheetAnimation.h"

class Coin : public GameObject
{
public:
	Coin(AnimationInfo* animInfo);
	~Coin();

	int cur;
	int flipCount;
	float takenTime;
	bool isLastCoin;
	std::list<float> delayTimes;

	AnimationInfo* animRenderer;
	std::vector<SheetAnimation*> coinAnimList;

	virtual void Update();
	void FlipWithDelay(float delayTime);
	void FlipCoin();
	int GetCurrentCur();
};

