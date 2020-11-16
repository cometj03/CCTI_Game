#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "CircleCollider.h"
class Bullet :
	public GameObject
{
public:
	AABBCollider* col;
	float speed, speedRate;	//속도, 가속도
	float angle, angleRate;//각도, 각속도

	Bullet(const wchar_t* imagePath);
	~Bullet();

	virtual void Update();

	//총알의 이동
	void Move();			//움직이는함수

	//총알의 충돌
	void CheckOutOfScreen();	//총알 화면 벗어났나 체크
	virtual void OnCollision(GameObject* other);
	virtual void OnDestroy();//삭제시 함수
};

