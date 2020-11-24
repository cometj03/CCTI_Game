#include "stdafx.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "Scene.h"


Bullet::Bullet(const wchar_t* imagePath)
	:GameObject(imagePath)
{
	//충돌체를 생성합니다.
	col = new AABBCollider(this,renderer);
	//충돌체를 Scene에 등록합니다.
	Scene::PushOnCurrentScene(col);

	//기타 값들을 초기화합니다.
	speed = 0.0f;
	speedRate = 0.0f;
	angle = 0.0f;
	angleRate = 0.0f;

	//tag를 등록합니다. 충돌 처리에 사용됩니다.
	tag = Tag::Bullet;
}

Bullet::~Bullet() {
	//충돌체를 생성하면 반드시 직접 삭제해 주어야 합니다.
	SAFE_DELETE(col);
}

void Bullet::Update()
{
	Move();
	CheckOutOfScreen();
}

void Bullet::Move()
{
	//position을 각도, 속도에 따라 업데이트하여 움직입니다.
	transform->position.x
		+= (speed * cosf(angle) * TimeManager::GetDeltaTime());
	transform->position.y
		+= (speed * sinf(angle) * TimeManager::GetDeltaTime());

	speed += speedRate * TimeManager::GetDeltaTime();
	angle += angleRate * TimeManager::GetDeltaTime();
}

void Bullet::CheckOutOfScreen()
{
	//화면 밖으로 나갔는지 여부를 체크합니다.
	if (!Camera::GetCamera()->IsOnScreen(col))
	{
		//printf("화면 밖에 나감!\n");
		Scene::Destroy(this);
	}
}

//OnCollision: 충돌이 감지되었을 때 호출됩니다.
void Bullet::OnCollision(GameObject* other)
{
	//충돌한 대상이 적일 경우 총알을 삭제합니다.
	if (other->tag == Tag::Enemy)
	{
		Scene::Destroy(this);
	}
}

//OnDestroy: 게임오브젝트가 삭제될 때 호출됩니다.
void Bullet::OnDestroy() {
	//std::cout << "총알 삭제됨 ㅠㅠ\n";
}
