#pragma once
#include "Bullet.h"

//총알을 발사하는 역할을 합니다.
//실제 수업에선 Player에서 직접 Shoot()을 구현하여 사용하였습니다.
//이 방식이 조금 더 객체지향적이고, 이 방식의 장점은 Gun을 상속받아 여러 종류의 총알 발사 형태를 구현할 수 있다는 것입니다.

class Gun
{
public:
	//총 속성
	int bulletCount;
	float bulletGap;
	float bulletSpeed;

	//총알 딜레이 계산
	float timer;
	float delay;
	bool canShoot;
public:
	Gun(float delay, float bulletSpeed = 1000.0f, int bulletCount = 1, float bulletGap = 0.1f);

	void UpdateDelay();
	void Shoot(Vector2 playerPosition, float angle);
};

