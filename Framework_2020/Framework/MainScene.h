#pragma once
#include "Scene.h"

class MainScene : public Scene
{
public:
	MainScene();
	~MainScene();

	GameObject* background;
	GameObject* logo;
	GameObject* playButton;

	virtual void Initialize();
};

