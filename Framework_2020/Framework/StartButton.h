#pragma once
#include "Button.h"

//스타트 버튼입니다.
//Button이라는 클래스를 상속받습니다.
//Framework에 자체 구현된 클래스는 아니고, 바로 StartScene 필터 내에 만들어져 있습니다.
class StartButton :
	public Button
{
public:
	StartButton(const wchar_t* uri);
	void OnClick();
};

