#include "stdafx.h"
#include "BoardScene.h"

BoardScene::BoardScene()
{
}

BoardScene::~BoardScene()
{
}

void BoardScene::Initialize()
{
	background = Push(new GameObject(L"resources/image/board_1.png"));	
	
	/*
	* 0 1 2
	* 3 4 5
	* 6 7 8
	*/
	for (int i = 0; i < 9; i++) 
	{
		coins.push_back(new Coin(new AnimationInfo));
		float coinPosX = (i % 3 - 1) * BOARD_INTERVAL;
		float coinPosY = -(i / 3 - 1) * BOARD_INTERVAL;
		coins[i]->transform->SetPosition(coinPosX, coinPosY);
		Push(coins[i]);
	}
	
	arrow = new Arrow(new AnimationInfo);
	arrow->PutCoins(coins);
	Push(arrow);
}
