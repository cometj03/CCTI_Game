#pragma once
#include "Scene.h"
#include "Arrow.h"
#include "Coin.h"
#include "Tile.h"

#define BOARD_INTERVAL 75	// 보드 한 칸 사이의 간격

class BoardScene : public Scene
{
public:
	BoardScene();
	~BoardScene();

	GameObject* background;
	GameObject* board;
	Tile* tile;
	Arrow* arrow;
	std::vector<Coin*> coins;

	virtual void Initialize();
};

