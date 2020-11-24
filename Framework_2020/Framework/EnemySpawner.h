#pragma once
#include "Enemy.h"

//매 프레임 랜덤한 위치에 적을 생성합니다.

class EnemySpawner :
	public GameObject
{
public:
	EnemySpawner(Transform* playerTransform);
	~EnemySpawner();

	void Update();
	
	Transform* playerTransform;
	float timer;
	float spawnDelay;
	void UpdateTimer();
	void Spawn();
};

