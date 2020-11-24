#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Bullet.h"
#include "Scene.h"
#include "EndingScene.h"
#include "ScoreManager.h"


//생성자입니다.
Player::Player()
	:GameObject(L"resources/Player.png"),
	moveSpeed(300.0f), timer(0.0f), delay(3.0f)
{
	//태그를 지정합니다.
	tag = Tag::Player;

	//총알을 발사할 Gun 오브젝트를 추가합니다.
	//이 오브젝트에서 Shoot 함수를 구현하였습니다.
	gun = new Gun(0.5f, 1000.0f, 3, 0.1f * PI);
	
	//충돌체를 추가합니다.
	col = new AABBCollider(this, renderer);
	//충돌체를 Scene에 Push합니다.
	//충돌체이기 때문에 충돌 검사를 Scnee에서 해줘야 합니다.
	Scene::PushOnCurrentScene(col);

	//SoundEvent: 소리 출력을 위한 객체입니다.
	//se를 동적할당하고, LoadFile을 통해 음악 객체를 가져와야 합니다.
	//근데 사실 제가 사운드를 많이 만져본게 아니라 가끔 터지더라고요 ㅈㅅ
	se = new SoundEvent();
	se->LoadFile(L"resources/laser.mp3");

	bgm = new SoundEvent();
	bgm->LoadFile(L"resources/test.wav");
	//Play 함수로 노래 재생이 가능합니다.
	bgm->Play();
}
Player::~Player()
{
	//충돌체, soundevent는 반드시 생성 후 삭제해야 합니다.
	//콜라이더는 Scene에서 삭제 구현을 안해놨어요
	SAFE_DELETE(col);
	SAFE_DELETE(se);
	SAFE_DELETE(bgm);

	//gun은 GameObject로써 Scene에 등록되지 않았기 때문에
	//우리가 직접 삭제해주어야 합니다.
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
	//총알 발사를 담당합니다.
	//gun은 GameObject가 아닌 그냥 클래스이므로 Update함수를 직접 호출해줍니다.
	gun->UpdateDelay();

	//마우스 각도를 계산합니다.
	float angle = ComputeMouseAngle();

	//버튼이 눌렸다면 총알을 발사합니다.
	if (InputManager::GetKeyDown(VK_LBUTTON) || InputManager::GetKeyDown(VK_SPACE))
	{
		//소리를 재생합니다.
		se->Stop();
		se->Play();
		//총알을 생성합니다.
		gun->Shoot(transform->position, angle);
	}
	//마우스 방향으로 바라보게 합니다.
	transform->rotatingAngle = angle;
}


//마우스 방향으로 각도를 계산합니다.
float Player::ComputeMouseAngle()
{
	//InputManger::GetMouseX,Y: 마우스 위치를 받아옵니다.
	Vector2 mouse(
		(float)InputManager::GetMouseX(),
		(float)InputManager::GetMouseY()
	);

	//ScreenPosition으로 주어지는 마우스 위치를 World좌표로 변환합니다.
	Vector2 mouseInWorld = Camera::ScreenPositionToWorld(mouse);

	//각도를 계산합니다.
	return atan2f(
		mouseInWorld.y - transform->position.y,
		mouseInWorld.x - transform->position.x);
}

//OnCollision: 충돌 감지시 호출됩니다.
void Player::OnCollision(GameObject* other)
{
	//적과 충돌하였을 경우 실행합니다.
	//충돌 후 잠깐 delay를 주어 무적 시간을 만듭니다.
	if (timer > delay && other->tag == Tag::Enemy)
	{
		hp -= 1;
		std::cout << "체력이 1 달았습니다. 현재" << hp << "남음\n";
		timer = 0.0f;
	}
	if (hp == 0)
	{
		std::cout << "게임 오바";
		Scene::ChangeScene(new EndingScene(ScoreManager::instance->score));
	}
}

//충돌 시 잠시 무적 시간을 줍니다.
//바로 위의 OnCollision에서 timer값이 조절됩니다.
//이 함수 자체는 Update에서 매 프레임 실행됩니다.
void Player::CollisionTimer()
{
	if (timer <= delay)
	{
		timer += TimeManager::GetDeltaTime();
		renderer->alpha = 0.5f;
	}
	else
	{
		renderer->alpha = 1.0f;
	}
}

