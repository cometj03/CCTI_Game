#include "stdafx.h"
#include "TestScene.h"
#include "FontObject.h"
void TestScene::Initialize()
{
	testObject = new AnimationObject(new AnimationInfo());
	Push(testObject);

	//UI 오브젝트는, 카메라와 상관없이 화면 상의 위치를 기준으로 합니다.
	FontObject* fo = new FontObject();
	PushUI(fo);
	fo->transform->SetPosition(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
}
