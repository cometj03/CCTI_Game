#include "stdafx.h"
#include "Enemy.h"
#include "Scene.h"
#include "TimeManager.h"
#include "ScoreManager.h"

Enemy::Enemy(const wchar_t* imagePath, float moveSpeed, int hp, Transform* playerTransform)
	: GameObject(imagePath),hp(hp),moveSpeed(moveSpeed), playerTransform(playerTransform)
{
	//충돌을 감지하기 위해 충돌체를 제작합니다.
	col = new AABBCollider(
		this,
		renderer
	);
	//충돌체를 현재 Scene에 추가합니다.
	Scene::PushOnCurrentScene(col);

	//이 오브젝트에 Tag를 등록합니다. Enemy로 등록하였습니다. 이후 충돌처리 때 사용합니다.
	tag = Tag::Enemy;
}

Enemy::~Enemy(){
	//충돌체를 사용할 경우 반드시 초기화가 필요합니다.
	SAFE_DELETE(col);
}

void Enemy::Update()
{
	Move();
}

void Enemy::Move()
{
	Vector2 aim = (playerTransform->position - transform->position).normalized();
	transform->SetRotation(atan2f(aim.y, aim.x));
	transform->position.x += aim.x * moveSpeed * TimeManager::GetDeltaTime();
	transform->position.y += aim.y * moveSpeed * TimeManager::GetDeltaTime();
}

//OnCollision: 충돌이 감지되었을 때 호출됩니다.
void Enemy::OnCollision(GameObject* other)
{
	//충돌체가 Bullet일 경우에만 체력을 깎습니다.
	if (other->tag == Tag::Bullet)
	{
		--hp;
	}

	//체력이 0보다 낮을 경우 점수를 더하고 이 객체를 삭제합니다.
	if (hp <= 0)
	{
		Scene::Destroy(this);
		ScoreManager::AddScore(10);
	}
}