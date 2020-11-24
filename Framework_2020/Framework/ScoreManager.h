#pragma once
#include "GameObject.h"
#include "FontInfo.h"

//점수 처리를 관리하는 객체입니다.
//기본적으로 text를 출력하는 객체입니다. (FontInfo사용)
//싱글턴 패턴을 활용하여 다른 모든 객체에서 접근이 가능합니다. 싱글턴은 구글링하시거나 저에게 질문 주세요.
//매 프레임 점수를 저장하고, 그 값을 텍스트에 업데이트 합니다.

class ScoreManager :
	public GameObject
{
public:
	Font* font;
	FontInfo* fontRenderer;
	int score;

public:
	ScoreManager();
	~ScoreManager();

	void UpdateScore();

public:
	static ScoreManager* instance;
	static void AddScore(int value);
};

