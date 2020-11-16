#pragma once
#include "stdafx.h"
#include "AABBCollider.h"
#include "CircleCollider.h"
class CollisionManager
{
public:
	~CollisionManager();
public:
	std::list<GameObject*> gameObjectList;
	std::list<AABBCollider*> aabbList;
	std::list<CircleCollider*> circleList;

public:
	AABBCollider* PushBackCollider(AABBCollider* col);
	CircleCollider* PushBackCollider(CircleCollider* col);
	void RemoveGameObject(GameObject* g);
public:
	void Update();

public:
	static bool Intersected(AABBCollider* a, AABBCollider* b);
	static bool Intersected(CircleCollider* a, CircleCollider* b);
	static bool Intersected(AABBCollider* a, CircleCollider* b);
};

