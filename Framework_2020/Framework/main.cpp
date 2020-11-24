#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "TestScene.h"
#include "StartScene.h"

//기본 메인 함수입니다.

int main()
{
	//프레임워크 전체를 관리하는 객체입니다.
	Framework* f = new Framework;
	//시작 Scene, 게임 타이틀, 해상도(가로, 세로), 창모드 여부를 결정합니다.
	f->Run(new StartScene(),L"타이틀", 800,600, false);
	SAFE_DELETE(f);

	//메모리 누수를 확인할 때 사용합니다. stdafx.h를 참고하세요.
	//_CrtDumpMemoryLeaks();
	return 0;
}