#pragma once
#include "Scene.h"
#include "AnimationObject.h"
class TestScene :
	public Scene
{
public:
	virtual void Initialize();	//생성자가 아닌, Initialize함수에서 초기화를 진행합니다.
								//ChangeScene에서 코드가 꼬이는 것을 방지합니다.

	AnimationObject* testObject;

};

