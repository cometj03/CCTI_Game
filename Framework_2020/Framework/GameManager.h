#pragma once
#include "ScoreText.h"
#include "Coin.h"
#include "Tile.h"

#define MAX_TURN 500
#define TURN_INTERVAL 3

class GameManager// : public GameObject
{
public:
	GameManager();

public:
	static void Init();
	static void AddScore(int d);

	static void TurnUpdate();
	static void GameCheck();

	static GameManager* GetInstance();

	// 임시로 arrow update에서 실행
	static void Update();	// 게임이 클리어 됐을 때 딜레이를 주기 위함
	float delayTime;

	// 전체적인 게임 변수
	int score;
	int currentTurn;
	int maxTurn;
	bool isGameClear;

	// 힌트 관련 변수
	int hintPos;
	bool isHintTime;

	ScoreText* scoreText;
	static void PutScoreText(ScoreText* st);

	std::vector<Coin*> coins;
	static void PutCoins(std::vector<Coin*> &c);

	Tile* tile;
	static void PutTile(Tile* t);
};

