#include "stdafx.h"
#include "TimeManager.h"

TimeManager::TimeManager(){}
TimeManager::~TimeManager(){}

float TimeManager::deltaTime;

//DeltaTime을 매 프레임 계산해줍니다.
//Framework의 MainLoop에서 매 프레임 호출됩니다.
//현재 시각 - 이전 프레임의 시각을 계산하여 DeltaTime을 계산합니다.
void TimeManager::UpdateTime()
{
	static DWORD oldTime = timeGetTime();

	DWORD curTime = timeGetTime();
	deltaTime = (float)(curTime - oldTime)*0.001f;
	oldTime = curTime;
}

//static 함수입니다. 저장된 Delta Time을 불러옵니다.
float TimeManager::GetDeltaTime()
{//getter함수
	return deltaTime;
}
