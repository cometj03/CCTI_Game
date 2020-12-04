#include "stdafx.h"
#include "Coin.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "GameManager.h"

Coin::Coin(AnimationInfo* animInfo)
	: GameObject(animInfo), cur(0), flipCount(0), takenTime(0), isLastCoin(0)
{
	delayTimes.clear();
	animRenderer = animInfo;

	// state : 0~1, 초당 16프레임, 경로, 가로 개수, 전체 개수
	coinAnimList.push_back(new SheetAnimation(0, 30.0f, L"resources/image/coin_sheet_1.png", 8, 8));
	coinAnimList.push_back(new SheetAnimation(1, 30.0f, L"resources/image/coin_sheet_2.png", 8, 8));
	coinAnimList[0]->SetAnimateOnce(true);
	coinAnimList[1]->SetAnimateOnce(true);

	for (int i = 0; i < 2; i++)
		animRenderer->PushBackAnimation(coinAnimList[i]);
}

Coin::~Coin()
{
}

void Coin::Update()
{
	if (flipCount > 0)
	{
		// 쿨타임 계산
		if (delayTimes.front() >= takenTime)
		{
			takenTime += TimeManager::GetDeltaTime();
		}
		else
		{
			// 쿨타임 끝
			this->FlipCoin();
			takenTime = 0;
			flipCount--;
			delayTimes.pop_front();	// 끝나면 하나씩 빼줌
		}
	}
}

void Coin::FlipWithDelay(float delayTime)
{
	// 횟수 1 더해줌 -> 중복 방지 위함
	flipCount++;
	delayTimes.push_back(delayTime);
}

void Coin::FlipCoin()
{
	if (cur == 1) 
	{
		cur = 0;
		animRenderer->ChangeAnimation(0);
	}
	else 
	{
		cur = 1;
		animRenderer->ChangeAnimation(1);
	}

	// TODO: 조건부 버그 수정하기 : 힌트랑 같은 줄을 뒤집으면 버그 발생
	// 내생각엔 isLastCoin 변수가 겹쳐서 생기는 버그 같음
	// 리스트로 만들기
	// bool 로 만들기
	if (isLastCoin) {
		std::cout << "체크됨" << std::endl;
		GameManager::GetInstance()->GameCheck();
		isLastCoin = false;
	}
}

int Coin::GetCurrentCur()
{
	return cur;
}

void Coin::SetLastCoin()
{
	this->isLastCoin = true;
}
