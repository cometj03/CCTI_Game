#pragma once
#include "Scene.h"
#include "Arrow.h"
#include "Coin.h"

#define BOARD_INTERVAL 75	// 보드 한 칸 사이의 간격

class BoardScene : public Scene
{
public:
	BoardScene();
	~BoardScene();

	GameObject* background;
	Arrow* arrow;
	std::vector<Coin*> coins;

	virtual void Initialize();
};

