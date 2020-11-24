#include "stdafx.h"
#include "ScoreManager.h"

//전역 변수로써 싱글턴 패턴에 사용됩니다.
//싱글턴 패턴은 구글링하시거나 저에게 질문 주세요.
ScoreManager* ScoreManager::instance;

//여러 값들을 초기화합니다.
//텍스트를 렌더링하는 객체이므로, Renderer로 FontInfo를 사용합니다.
ScoreManager::ScoreManager()
	:GameObject(fontRenderer = new FontInfo()), score(0)
{
	//font 값들을 초기화합니다.
	font = new Font(L"궁서", 20.0f, 1.0f, 1.0f, 1.0f, 1.0f, false);
	fontRenderer->font = this->font;
	fontRenderer->text = L"Score: " + std::to_wstring(score);
	
	transform->SetPosition(WinApp::GetScreenWidthF()*0.5f,10.0f);

	instance = this;
}

ScoreManager::~ScoreManager()
{
	//font 사용 후에는 초기화 해주어야 합니다.
	SAFE_DELETE(font);
	instance = nullptr;
}

void ScoreManager::UpdateScore()
{
	//score값에 따라 text를 업데이트합니다.
	instance->fontRenderer->text = L"Score: " + std::to_wstring(instance->score);
}

//싱글턴 객체에 점수를 추가합니다.
void ScoreManager::AddScore(int value)
{
	instance->score += value;
	instance->UpdateScore();
}
