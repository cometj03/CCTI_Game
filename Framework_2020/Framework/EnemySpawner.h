#pragma once
#include "Enemy.h"

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

