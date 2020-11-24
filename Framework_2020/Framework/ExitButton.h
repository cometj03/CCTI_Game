#pragma once
#include "Button.h"


//엑시트 버튼입니다.
//Button이라는 클래스를 상속받습니다.
//Framework에 자체 구현된 클래스는 아니고, 바로 StartScene 필터 내에 만들어져 있습니다.
class ExitButton :
	public Button
{
public:
	ExitButton(const wchar_t* uri);
	void OnClick();
};

