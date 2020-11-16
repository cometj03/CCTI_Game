#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	background = Push(new GameObject(L"resources/background.png"));
	player = (Player*)Push(new Player());
	enemy = new Enemy(L"resources/Enemy.png",100.0f,30,player->transform);
	Push(enemy);
	enemy->transform->SetPosition(0.0f, 300.0f);

	spawner = new EnemySpawner(player->transform);
	Push(spawner);
}
