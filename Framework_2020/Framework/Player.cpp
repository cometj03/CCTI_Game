#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Bullet.h"
#include "Scene.h"
#include "TestScene.h"
Player::Player()
	:GameObject(L"resources/Player.png"),
	moveSpeed(300.0f), timer(0.0f), delay(3.0f)
{
	tag = Tag::Player;
	gun = new Gun(0.5f, 1000.0f, 3, 0.1f * PI);
	col = new AABBCollider(this, renderer);
	Scene::PushOnCurrentScene(col);
	se = new SoundEvent();
	se->LoadFile(L"resources/test.wav");
}
Player::~Player()
{
	SAFE_DELETE(col);
	SAFE_DELETE(se);
	SAFE_DELETE(gun);
}
void Player::Update() {
	//매 프레임 호출
	Move();
	Shoot();
	CollisionTimer();
}

void Player::Move()
{
	//움직임을 담당
	Vector2 input(0.0f, 0.0f);
	if (InputManager::GetKeyState('S'))
	{
		input.y -= 1.0f;
	}
	if (InputManager::GetKeyState('D'))
	{
		input.x += 1.0f;
	}
	if (InputManager::GetKeyState('W'))
	{
		input.y += 1.0f;
	}
	if (InputManager::GetKeyState('A'))
	{
		input.x -= 1.0f;
	}
	if (input.x!=0.0f||input.y!=0.0f)
	{
		input = input.normalized();
		transform->position.x += moveSpeed * input.x * TimeManager::GetDeltaTime();
		transform->position.y += moveSpeed * input.y * TimeManager::GetDeltaTime();
	}
}

void Player::Shoot()
{
	gun->UpdateDelay();
	float angle = ComputeMouseAngle();
	if (InputManager::GetKeyDown(VK_LBUTTON))
	{
		se->Play();
		gun->Shoot(transform->position, angle);
	}
	if (InputManager::GetKeyUp(VK_LBUTTON))
	{
		se->Stop();
	}
	transform->rotatingAngle = angle;
}

float Player::ComputeMouseAngle()
{
	Vector2 mouse(
		(float)InputManager::GetMouseX(),
		(float)InputManager::GetMouseY()
	);
	Vector2 mouseInWorld = Camera::ScreenPositionToWorld(mouse);
	return atan2f(
		mouseInWorld.y - transform->position.y,
		mouseInWorld.x - transform->position.x);
}

void Player::OnCollision(GameObject* other)
{
	if (timer > delay && other->tag == Tag::Enemy)
	{
		hp -= 1;
		std::cout << "체력이 1 달았습니다. 현재" << hp << "남음\n";
		timer = 0.0f;

		if (hp == 0)
		{
			std::cout << "게임 오바";
			Scene::ChangeScene(new TestScene());
		}
	}
}

void Player::CollisionTimer()
{
	if (timer <= delay)
	{
		timer += TimeManager::GetDeltaTime();
	}
}

