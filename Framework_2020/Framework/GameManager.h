#pragma once
#include "ScoreText.h"
#include "Coin.h"
#include "Tile.h"

#define MAX_TURN 100
#define TURN_INTERVAL 3

class GameManager
{
public:
	GameManager();

public:
	static void Init();
	static void AddScore(int d);

	static void GameManagerUpdate();

	static GameManager* GetInstance();

	int score;
	int currentTurn;
	int maxTurn;

	ScoreText* scoreText;
	static void PutScoreText(ScoreText* st);

	std::vector<Coin*> coins;
	static void PutCoins(std::vector<Coin*> &c);

	Tile* tile;
	static void PutTile(Tile* t);
};

