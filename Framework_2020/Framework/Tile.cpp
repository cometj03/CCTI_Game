#include "stdafx.h"
#include "Tile.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Random.h"

Tile::Tile() :
	GameObject(L"resources/image/tile_1.png"), alpha(0)
{
	isIn = isOut = false;
	renderer->alpha = 0;
}

Tile::~Tile()
{
}

void Tile::Update()
{
	if (InputManager::GetKeyDown('Q'))
		FadeIn(Random::Range(0, 8));

	if (isIn)
	{
		// FadeIn 할 자리
		if (alpha < 1) {
			alpha += TimeManager::GetDeltaTime();
			renderer->alpha = alpha;
		}
		else {
			alpha = 1;
			renderer->alpha = 1;
			isIn = false;
		}
	}
	else if (isOut)
	{
		// FadeOut 할 자리

	}
}

void Tile::FadeIn(int pos)
{
	float posX = (pos % 3 - 1) * 75;
	float posY = -(pos / 3 - 1) * 75;
	transform->SetPosition(posX, posY);

	renderer->alpha = alpha = 0;
	isIn = true;
}

void Tile::FadeOut()
{
}
