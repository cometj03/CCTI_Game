#include "stdafx.h"
#include "GameManager.h"
#include "OverScene.h"
#include "Random.h"
#include "TimeManager.h"

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

void GameManager::Update()
{
	GameManager* i = GetInstance();
	
	// 클리어시 딜레이 0.5초
	if (i->isGameClear)
	{
		if (i->delayTime < 0.5f)
			i->delayTime += TimeManager::GetDeltaTime();
		else {
			DEBUG("Clear!")
			Scene::ChangeScene(new OverScene(i->score));
		}
	}
}

void GameManager::Init()
{
	GameManager* i = GetInstance();

	i->currentTurn = 0;
	i->maxTurn = MAX_TURN;
	i->score = MAX_TURN;
	i->isHintTime = false;

	i->delayTime = 0;
	i->isGameClear = false;
}

void GameManager::AddScore(int d)
{
	GameManager* i = GetInstance();

	i->score += d;
	i->scoreText->UpdateScore();

	if (i->score <= 0)
		Scene::ChangeScene(new OverScene());	// 게임 오버
}

void GameManager::TurnUpdate()
{
	// 턴 시작 때 실행
	GameManager* i = GetInstance();

	i->currentTurn++;

	// 힌트 처리
	if (i->currentTurn % TURN_INTERVAL == TURN_INTERVAL - 1) {	// 세 턴에 한 번씩 타일 생성
		i->hintPos = Random::Range(0, 8);
		i->tile->FadeIn(i->hintPos);
		i->isHintTime = true;
		std::cout << "힌트 준비됨 : " << i->hintPos << std::endl;
	}
	else if (i->currentTurn % TURN_INTERVAL == 0) {	// 그 다음턴일 때 사라짐
		std::cout << "힌트 끝 : " << i->hintPos << std::endl;
		i->tile->FadeOut(i->hintPos);
		i->isHintTime = false;
	}
}

void GameManager::GameCheck()
{
	// 턴이 다 끝났을 때 실행
	GameManager* i = GetInstance();

	// 모두 같은 면인지 체크
	i->isGameClear = true;
	for (int k = 0; k < i->coins.size() - 1; k++) {
		// 지금 것과 다음 것이 같은지 -> 다르면 flag = false
		if (i->isGameClear && i->coins[k]->GetCurrentCur() == i->coins[k + 1]->GetCurrentCur()) {
			i->isGameClear = true;
		}
		else {
			i->isGameClear = false;
		}
	}

	// debug
	for (int j = 0; j < i->coins.size(); j++) {
		std::cout << i->coins[j]->GetCurrentCur() << " ";
		if (j % 3 == 2)
			std::cout << std::endl;
	}

	//if (flag)
		//Scene::ChangeScene(new OverScene(i->score));	// 클리어
}

void GameManager::PutScoreText(ScoreText* st)
{
	GetInstance()->scoreText = st;
}

void GameManager::PutCoins(std::vector<Coin*> &c)
{
	GetInstance()->coins = c;
}

void GameManager::PutTile(Tile* t)
{
	GetInstance()->tile = t;
}
