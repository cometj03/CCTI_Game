#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager* GameManager::GetInstance()
{
	static GameManager g;
	return &g;
}

void GameManager::Init()
{
	GameManager* gmr = GameManager::GetInstance();
	gmr->currentTurn = 0;
	gmr->maxTurn = MAX_TURN;
	gmr->score = MAX_TURN;
}

int GameManager::GetScore()
{
	GameManager* gmr = GameManager::GetInstance();
	gmr->score = gmr->maxTurn - gmr->currentTurn;
	std::cout << "현재 점수 : " << gmr->score << std::endl;
	return gmr->score;
}
