#include "stdafx.h"
#include "GameManager.h"
#include "OverScene.h"

GameManager::GameManager()
{
}

GameManager* GameManager::GetInstance()
{
	/* if (instance == nullptr) {
		static GameManager gmr;
		instance = &gmr;
	}
	return instance; */

	static GameManager gmr;
	return &gmr;
}

void GameManager::Init()
{
	GameManager* i = GetInstance();

	i->currentTurn = 0;
	i->maxTurn = MAX_TURN;
	i->score = MAX_TURN;
}

int GameManager::GetScore()
{
	GameManager* i = GetInstance();

	i->score = i->maxTurn - i->currentTurn;

	std::cout << "현재 점수 : " << i->score << std::endl;
	return i->score;
}

void GameManager::AddScore(int d)
{
	GameManager* i = GetInstance();

	i->score += d;
	i->scoreText->UpdateScore();

	if (i->score <= 0)
		Scene::ChangeScene(new OverScene());	// 게임 오버
}

void GameManager::PutScoreText(ScoreText* st)
{
	GameManager* i = GetInstance();

	i->scoreText = st;
}
