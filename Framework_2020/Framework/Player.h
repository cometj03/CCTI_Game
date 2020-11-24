#pragma once
#include "GameObject.h"
#include "Gun.h"
#include "SoundEvent.h"

//플레이어 객체입니다.
//이동, 총알 발사는 수업에서 한 내용과 거의 유사합니다.
//그 외에 충돌처리와 사운드 효과가 추가되었습니다.

class Player :
	public GameObject
{
public:
	Player();
	~Player();
	virtual void Update();	//업데이트 처리

	//Sound
	SoundEvent* se;
	SoundEvent* bgm;

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

