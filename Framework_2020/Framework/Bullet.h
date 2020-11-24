#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "CircleCollider.h"

//총알 객체입니다.
//각도, 속도 등의 값을 가지고 앞으로 날아갑니다.
//적과 만날 경우 충돌합니다.

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

	//OnCollision: 충돌이 감지되었을 때 호출됩니다.
	virtual void OnCollision(GameObject* other);
	//OnDestroy: 게임오브젝트가 삭제될 때 호출됩니다.
	virtual void OnDestroy();//삭제시 함수
};

