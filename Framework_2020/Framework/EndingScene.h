#pragma once
#include "Scene.h"

//죽을 경우 게임 엔딩을 나타냅니다.

class EndingScene :
	public Scene
{
public:
	std::wstring ment;

	//생성자로서 이전 Scene에서 점수 값을 받아옵니다.
	//생성자 이용은 Scene이 초기화되기 전에 호출되므로, 간단한 상수 값 받아오기 등에서만 사용을 권장합니다.
	EndingScene(int score);
	~EndingScene();

	//초기화 함수
	void Initialize();
};

