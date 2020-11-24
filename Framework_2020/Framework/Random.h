#pragma once
#include "stdafx.h"

//랜덤을 구현한 함수입니다.
//C++에서 지원하는 기능을 한 곳에 묶었습니다.
class Random
{
public:
	std::random_device randomDevice;
	std::mt19937 mersenne;

	Random();
public:
	//실제 게임 개발 중 사용될 함수입니다.
	//랜덤 오브젝트 자체를 받아옵니다.
	static Random* GetInstance();

	//static 함수로써 범위를 지정하면 해당 범위 내의 랜덤 값을 받아옵니다.
	static float Range(float min, float max);
	static int Range(int min, int max);
};

