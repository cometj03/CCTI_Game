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
	
	arrow = new Arrow(new AnimationInfo);
	Push(arrow);

	coins = new Coin(new AnimationInfo);
	Push(coins);
}
