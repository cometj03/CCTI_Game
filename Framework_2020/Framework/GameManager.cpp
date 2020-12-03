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

void GameManager::AddScore(int d)
{
	GameManager* i = GetInstance();

	i->score += d;
	i->scoreText->UpdateScore();

	if (i->score <= 0)
		Scene::ChangeScene(new OverScene());	// 게임 오버
}

void GameManager::GameManagerUpdate()
{
	// 턴이 다 끝났을 때 실행
	GameManager* i = GetInstance();

	// 모두 같은 면인지 체크
	bool flag = true;
	for (int k = 1; k < i->coins.size() - 1; k++) {
		// 지금 것과 다음 것이 같은지 -> 다르면 flag = false
		if (i->coins[k]->GetCurrentCur() != i->coins[k + 1]->GetCurrentCur()) {
			flag = false;
			break;
		}
	}

	if (flag)
		std::cout << "게임 클리어!" << std::endl;
}

void GameManager::PutScoreText(ScoreText* st)
{
	GetInstance()->scoreText = st;
}

void GameManager::PutCoins(std::vector<Coin*> &c)
{
	GetInstance()->coins = c;
}
