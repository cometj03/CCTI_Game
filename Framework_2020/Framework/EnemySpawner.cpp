#include "stdafx.h"
#include "EnemySpawner.h"
#include "TimeManager.h"
#include "Scene.h"
#include "Random.h"

EnemySpawner::EnemySpawner(Transform* playerTransform) 
	: GameObject(), timer(0.0f), playerTransform(playerTransform)
{
	spawnDelay = 1.0f;
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::Update()
{
	UpdateTimer();
	if (timer > spawnDelay)
	{
		Spawn();
	}
}

void EnemySpawner::UpdateTimer()
{
	timer += TimeManager::GetDeltaTime();
}

void EnemySpawner::Spawn()
{
	Enemy* enemy = new Enemy(L"resources/Enemy.png", 100.0f, 5, playerTransform);
	Vector2 v(Random::Range(-500.0f, 500.0f), Random::Range(-500.0f, 500.0f));
	//std::cout << "좀비 생성: " << v.x << ", " << v.y << "\n";
	enemy->transform->SetPosition(v);
	Scene::PushOnCurrentScene(enemy);

	timer = 0.0f;
}
