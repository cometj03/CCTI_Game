#pragma once
#include "stdafx.h"
#include "AABBCollider.h"
#include "CircleCollider.h"

//충돌을 처리하는 클래스입니다.
//각 Scene에서 한 번씩 호출됩니다.

class CollisionManager
{
public:
	//List의 요소들을 삭제합니다.
	~CollisionManager();
public:
	//오브젝트가 저장될 리스트입니다.
	std::list<GameObject*> gameObjectList;
	std::list<AABBCollider*> aabbList;
	std::list<CircleCollider*> circleList;

public:
	//리스트에 충돌체를 집어넣습니다.
	AABBCollider* PushBackCollider(AABBCollider* col);
	CircleCollider* PushBackCollider(CircleCollider* col);

	void RemoveGameObject(GameObject* g);
public:
	//충돌 처리를 진행합니다.
	void Update();

public:
	//충돌 여부를 확인합니다.
	//CollisionManager::Intersected처럼 static으로 사용 가능합니다.
	static bool Intersected(AABBCollider* a, AABBCollider* b);
	static bool Intersected(CircleCollider* a, CircleCollider* b);
	static bool Intersected(AABBCollider* a, CircleCollider* b);
};

