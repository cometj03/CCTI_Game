#include "stdafx.h"
#include "BoardScene.h"
#include "GameManager.h"
#include "ScoreText.h"

BoardScene::BoardScene()
{
}

BoardScene::~BoardScene()
{
}

void BoardScene::Initialize()
{
	GameManager::Init();	// 게임 매니저 초기화
	GameManager::GetScore();

	background = Push(new GameObject(L"resources/image/background.png"));
	board = Push(new GameObject(L"resources/image/board_1.png"));

	tile = (Tile*)Push(new Tile);
	
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

	ScoreText* st = new ScoreText(L"점수:");
	st->UpdateScore();
	PushUI(st);

	GameManager::PutScoreText(st);
}
