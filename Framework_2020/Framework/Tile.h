#pragma once
#include "GameObject.h"

class Tile : public GameObject
{
public:
	Tile();
	~Tile();

	virtual void Update();
	void FadeIn(int pos);
	void FadeOut(int pos);

	bool isIn, isOut;
	float alpha;
};

