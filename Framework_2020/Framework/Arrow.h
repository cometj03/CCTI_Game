#pragma once
#include "GameObject.h"
class Arrow : public GameObject
{
public:
	Arrow();
	~Arrow();

	virtual void Update();

	void Move();
};

