#include "stdafx.h"
#include "PlayButton.h"
#include "BoardScene.h"

PlayButton::PlayButton(const wchar_t* uri)
	: Button(uri)
{
}

void PlayButton::OnClick()
{
	std::cout << "Play\n";
	Scene::ChangeScene(new BoardScene());
}
