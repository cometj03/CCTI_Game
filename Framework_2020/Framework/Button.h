#pragma once
#include "GameScene.h"

//버튼을 구현합니다.
//매 업데이트마다 마우스 클릭&&마우스-상자 충돌이 일어났나 확인합니다.
//간단한 버튼은 이 버튼을 상속받아 구현하면 좋습니다.
//StartButton, ExitButton 클래스를 참고하면 어떻게 구현할 지 감이 올겁니다.
class Button :
	public GameObject
{
public:
	AABBCollider* col;
	Button(const wchar_t* uri);
	~Button();
	void Update();
	virtual void OnClick(){}
};

