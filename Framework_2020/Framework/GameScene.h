#pragma once
#include "Scene.h"
#include "Player.h"		
#include "Enemy.h"
#include "EnemySpawner.h"

//4,5일차 수업 시간에 함께 제작한 Scene입니다.

class GameScene : public Scene
{
public:
	virtual void Initialize();

	GameObject* background;	//배경 이미지
	Player* player;		//플레이어
	Enemy* enemy;		//적
	EnemySpawner* spawner;
};

