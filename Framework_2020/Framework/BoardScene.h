#pragma once
#include "Scene.h"
#include "Arrow.h"
#include "Coin.h"

class BoardScene : public Scene
{
public:
	BoardScene();
	~BoardScene();

	GameObject* background;
	Arrow* arrow;
	Coin* coins;	// TODO: 코인 배열 생성 후 코인 배치

	virtual void Initialize();
};

