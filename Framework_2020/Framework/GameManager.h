#pragma once

#define MAX_TURN 100

class GameManager
{
public:
	GameManager();

public:
	static GameManager* GetInstance();
	static void Init();
	static int GetScore();

	int score;
	int currentTurn;
	int maxTurn;
};

