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

void PlayButton::OnMouseHover()
{
	transform->SetScale(1.1f, 1.1f);
}

void PlayButton::OnMouseExit()
{
	transform->SetScale(1, 1);
}