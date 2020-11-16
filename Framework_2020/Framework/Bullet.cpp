#include "stdafx.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "Scene.h"


Bullet::Bullet(const wchar_t* imagePath)
	:GameObject(imagePath)
{
	col = new AABBCollider(this,renderer);
	Scene::PushOnCurrentScene(col);
	speed = 0.0f;
	speedRate = 0.0f;
	angle = 0.0f;
	angleRate = 0.0f;
	tag = Tag::Bullet;
}

Bullet::~Bullet() {
	SAFE_DELETE(col);
}

void Bullet::Update()
{
	Move();
	CheckOutOfScreen();
}

void Bullet::Move()
{
	transform->position.x
		+= (speed * cosf(angle) * TimeManager::GetDeltaTime());
	transform->position.y
		+= (speed * sinf(angle) * TimeManager::GetDeltaTime());

	speed += speedRate * TimeManager::GetDeltaTime();
	angle += angleRate * TimeManager::GetDeltaTime();
}

void Bullet::CheckOutOfScreen()
{
	if (!Camera::GetCamera()->IsOnScreen(col))
	{
		//printf("화면 밖에 나감!\n");
		Scene::Destroy(this);
	}
}

void Bullet::OnCollision(GameObject* other)
{
	if (other->tag == Tag::Enemy)
	{

		Scene::Destroy(this);
	}
}

void Bullet::OnDestroy() {
	//std::cout << "총알 삭제됨 ㅠㅠ\n";
}
