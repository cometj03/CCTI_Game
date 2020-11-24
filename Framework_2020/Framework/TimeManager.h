#pragma once
//시간을 계산하기 위한 클래스입니다.
//Framework 클래스에서 사용합니다.

class TimeManager
{
	friend class Framework;
public:
	TimeManager();
	~TimeManager();
private:
	static float deltaTime;

	static void UpdateTime();
public:
	static float GetDeltaTime();
};

