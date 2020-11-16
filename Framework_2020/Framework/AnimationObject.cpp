#include "stdafx.h"
#include "AnimationObject.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "GameScene.h"

AnimationObject::AnimationObject(AnimationInfo* animInfo)
	:GameObject(animInfo)		//'[1]'
{
	//애니메이션 적용 방법
	//ListAnimation(사진 여러장으로 애니메이션을 만듦)
	//SheetAnimation(사진 한장을 잘라서 애니메이션을 만듦, 애니메이션 시트 참조)
	//각 애니메이션 당 하나씩 동적할당을 통해 생성
	//Animation 클래스는 한 애니메이션을 담당하는 클래스입니다.
	//처음 인수 state는 애니메이션 등록 번호를 의미합니다.(enum등으로 관리 가능)
	//state 값이 겹치지 않게 해주세요.

	//AnimationInfo 클래스는 애니메이션들을 관리하고, 렌더링할 정보를 가진 클래스입니다.
	//해당 클래스를 사용하기 위해, 반드시 GameObject의 생성자에 AnimationInfo를 전달하여야 합니다. '[1]참조'
	this->animationRenderer = animInfo;

	//List Animation입니다. 동적할당해줍니다.
	testAnim1 = new ListAnimation(0,2.0f);				//state값은 0, 초당 2.0프레임 수행할 애니메이션입니다.
	testAnim1->PushBackSprite(L"resources/circle.png");	//출력할 이미지를 pushback 해줍니다.
	testAnim1->PushBackSprite(L"resources/square.png");
	animationRenderer->PushBackAnimation(testAnim1);	//AnimationInfo에 애니메이션을 푸쉬백합니다.

	//Sheet Animation입니다.
	//state값은 1, 초당 16.0프레임 수행할 애니메이션입니다.
	//sheet 애니메이션엔 오직 하나의 이미지 파일만이 필요하므로 생성자에서 이미지를 로드해줍니다.
	//row값은 sheet의 한 줄에 저장된 이미지의 수 입니다.
	//length는 sheet에 저장된 모든 이미지의 수 입니다.
	testAnim2 = new SheetAnimation(1, 16.0f, L"resources/sheet.png", 4, 16);
	animationRenderer->PushBackAnimation(testAnim2);//AnimationInfo에 애니메이션을 푸쉬백합니다.

	moveSpeed = 100.0f;	//이동 테스트

	cc = new CircleCollider(this, (float)renderer->GetWidth());
	Scene::PushOnCurrentScene(cc);
}

AnimationObject::~AnimationObject()
{
	SAFE_DELETE(cc);
}

void AnimationObject::Update()
{
	//움직임을 담당하는 부분입니다.
	//InputManager::GetKey~함수를 통해 입력을 체크할 수 있습니다.
	//4일차 수업 내용을 참고하세요.
	if (InputManager::GetKeyState(VK_UP))
		transform->position.y += moveSpeed * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState(VK_DOWN))
		transform->position.y -= moveSpeed * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState(VK_RIGHT))
		transform->position.x += moveSpeed * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState(VK_LEFT))
		transform->position.x -= moveSpeed * TimeManager::GetDeltaTime();

	//Scene 변경을 담당하는 부분입니다.
	if (InputManager::GetKeyDown(VK_RETURN))
	{
		//다음 Scene으로 변경할 준비를 합니다.
		//아래와 같은 형태로 호출하여 줍니다.
		//한번에 ChangeScene을 여러번 호출하지 않도록 주의해 주세요.
		Scene::ChangeScene(new GameScene());
	}

	//애니메이션 변경을 담당할 부분입니다.
	//애니메이션이 등록되어있다면, 처음에 지정한 state값을 호출하여 애니메이션을 변경할 수 있습니다.
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		static int cur = 0;
		if (cur == 0)
		{
			cur = 1;
			animationRenderer->ChangeAnimation(1);
		}
		else
		{
			cur = 0;
			animationRenderer->ChangeAnimation(0);
		}
	}

	if (InputManager::GetKeyDown(VK_LBUTTON) && cc->isMouseOn())
	{
		Scene::ChangeScene(new GameScene());
	}
}
