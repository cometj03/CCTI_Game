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
