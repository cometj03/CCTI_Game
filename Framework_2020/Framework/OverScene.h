#pragma once
#include "Scene.h"
#include "EndButton.h"

class OverScene : public Scene
{
public:
	OverScene();
	OverScene(int score);
	~OverScene();

	int score;
	bool isClear;

	GameObject* background;
	EndButton* homeButton;
	EndButton* againButton;

	virtual void Initialize();
};

