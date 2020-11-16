#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "TestScene.h"

int main()
{
	Framework* f = new Framework;
	//시작 Scene, 게임 타이틀, 해상도(가로, 세로), 창모드 여부를 결정합니다.
	f->Run(new TestScene(),L"타이틀", 800,600, false);
	SAFE_DELETE(f);

	return 0;
}