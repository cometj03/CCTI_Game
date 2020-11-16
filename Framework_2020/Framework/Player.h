#pragma once
#include "GameObject.h"
#include "Gun.h"
#include "SoundEvent.h"
class Player :
	public GameObject
{
public:
	Player();
	~Player();
	virtual void Update();	//업데이트 처리

	//Sound
	SoundEvent* se;

	//이동
	float moveSpeed;		//이동 속도
	void Move();

	//총알 발사
	Gun* gun;
	void Shoot();
	float ComputeMouseAngle();

	//몬스터와 충돌
	int hp = 3;
	AABBCollider* col;
	float timer;
	float delay;
	void OnCollision(GameObject* other);
	void CollisionTimer();
};

