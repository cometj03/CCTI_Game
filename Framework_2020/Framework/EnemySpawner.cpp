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

//시간을 업데이트합니다.
//만약 spawnDelay가 지났을 경우, 적을 생성합니다.
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

	//적 오브젝트를 만듭니다.
	Enemy* enemy = new Enemy(L"resources/Enemy.png", 100.0f, 5, playerTransform);

	//랜덤한 위치를 지정합니다. x축으로 -500~500, y축으로 -500~500 위치 중 랜덤으로 생성되게 됩니다.
	Vector2 v(Random::Range(-500.0f, 500.0f), Random::Range(-500.0f, 500.0f));
	enemy->transform->SetPosition(v);
	//std::cout << "좀비 생성: " << v.x << ", " << v.y << "\n";

	//현재 Scene에 Push합니다.
	Scene::PushOnCurrentScene(enemy);

	//몬스터를 생성하였으므로 생성 타이머를 다시 초기화합니다.
	timer = 0.0f;
}
