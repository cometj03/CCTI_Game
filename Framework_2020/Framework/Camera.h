#pragma once
//GameObject와 AABBCollider에 의존성을 가집니다.
#include "GameObject.h"
#include "AABBCollider.h"
#include "CircleCollider.h"

//Camera 클래스입니다.
//게임오브젝트로 구현되어있으며, 매 Scene에서 한번씩 생성됩니다.
//카메라의 게임 내 위치를 조정하여 시야를 수정할 수 있습니다.

class Camera :
	public GameObject
{
private:
	//화면의 가로세로 길이입니다.
	float screenWidth;
	float screenHeight;

	//가로세로 길이*0.5f입니다.
	float halfWidth;
	float halfHeight;

	//화면 전체를 Collider로써 저장합니다.
	AABBCollider* screenBox;
public:
	Camera();
	virtual ~Camera();	//상속될 가능성이 있다면 소멸자를 Virtual로 호출해주어야 합니다.

	//화면 좌표<->월드 좌표 변환 함수들입니다.
	//월드 좌표(World Position): x축: 오른쪽, y축: 위쪽, 맨처음 화면 중앙이 영점
	//화면 좌표(Screen Position): x축: 오른쪽, y축: 아래쪽, 실제 모니터 화면의 가장 왼쪽 위가 영점
	static Vector2 WorldPositionToScreen(const Vector2& worldPosition);
	static Vector2 ScreenPositionToWorld(const Vector2& screenPosition);

	//콜라이더를 입력받아 Screen 위에 있는지 확인합니다.
	static bool IsOnScreen(AABBCollider* col);
	static bool IsOnScreen(CircleCollider* col);

public:
	//현재 Scene의 카메라를 받아옵니다.
	static Camera* GetCamera();

	//게임오브젝트로써 Update합니다.
	void Update();
};

