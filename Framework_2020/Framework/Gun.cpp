#include "stdafx.h"
#include "Gun.h"
#include "Scene.h"
#include "TimeManager.h"

Gun::Gun(float delay,float bulletSpeed, int bulletCount, float bulletGap)
	: delay(delay), bulletSpeed(bulletSpeed), bulletCount(bulletCount), bulletGap(bulletGap), timer(0.0f), canShoot(true)
{
}

void Gun::UpdateDelay()
{
	//딜레이를 계산합니다.
	//tiemr 값이 delay를 넘으면 발사가 가능해집니다.
	if (timer < delay)
	{
		timer += TimeManager::GetDeltaTime();
		canShoot = false;
	}
	else
	{
		canShoot = true;
	}
}

void Gun::Shoot(Vector2 playerPosition, float angle)
{
	//발사가 가능할 경우, 이 함수를 소유하고 있는 객체에서 호출하게 됩니다. (ex: Player)
	//지정된 각도, 방향, 총알 수 등을 발사하게 됩니다.
	if (canShoot)
	{
		float startangle = angle - ((float)bulletCount - 1.0f) * 0.5f * bulletGap;
		for (int i = 0; i < bulletCount; ++i)
		{
			Bullet* b = new Bullet(L"resources/bullet.png");
			b->transform->SetPosition(playerPosition);
			b->speed = bulletSpeed;
			b->angle = startangle+bulletGap*(float)i;
			b->transform->SetRotation(b->angle + 0.5f * PI);
			Scene::PushOnCurrentScene(b);
		}
	}
}
