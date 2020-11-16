#include "stdafx.h"
#include "Random.h"

Random::Random()
	:mersenne(randomDevice())
{
}

Random* Random::GetInstance()
{
	static Random r;
	return &r;
}

float Random::Range(float min, float max)
{
	Random* r = GetInstance();
	std::uniform_real_distribution<> res(min, max);
	return (float)res(r->mersenne);
}

int Random::Range(int min, int max)
{
	Random* r = GetInstance();
	std::uniform_int_distribution<> res(min, max);
	return res(r->mersenne);
}
