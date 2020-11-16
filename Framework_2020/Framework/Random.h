#pragma once
#include "stdafx.h"
class Random
{
public:
	std::random_device randomDevice;
	std::mt19937 mersenne;

	Random();
public:
	static Random* GetInstance();
	static float Range(float min, float max);
	static int Range(int min, int max);
};

