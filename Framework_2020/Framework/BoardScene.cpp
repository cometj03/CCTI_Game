#include "stdafx.h"
#include "BoardScene.h"

BoardScene::BoardScene()
{
}

BoardScene::~BoardScene()
{
}

void BoardScene::Initialize()
{
	background = Push(new GameObject(L"resources/image/board_1.png"));
	arrow = new Arrow();
	arrow->transform->SetPosition(-155, 75);
	Push(arrow);
}
