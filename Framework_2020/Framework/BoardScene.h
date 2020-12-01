#pragma once
#include "Scene.h"
#include "Arrow.h"

class BoardScene : public Scene
{
public:
	BoardScene();
	~BoardScene();

	GameObject* background;
	Arrow* arrow;

	virtual void Initialize();
};

