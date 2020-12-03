#pragma once
#include "ScoreText.h"

#define MAX_TURN 100

class GameManager
{
public:
	GameManager();

public:
	static void Init();
	static int GetScore();
	static void AddScore(int d);
	static void PutScoreText(ScoreText* st);

	static GameManager* GetInstance();

	int score;
	int currentTurn;
	int maxTurn;

	ScoreText* scoreText;
};

