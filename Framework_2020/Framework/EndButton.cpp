#include "stdafx.h"
#include "EndButton.h"
#include "BoardScene.h"
#include "MainScene.h"

EndButton::EndButton(const wchar_t* uri, int id) :
	Button(uri), id(id)
{
}

void EndButton::OnClick()
{
	if (id == 0)
	{
		// HomeButton
		std::cout << "Home" << std::endl;
		Scene::ChangeScene(new MainScene());
	}
	else if (id == 1) 
	{
		// AgainButton
		std::cout << "Again" << std::endl;
		Scene::ChangeScene(new BoardScene());
	}
}

void EndButton::OnMouseHover()
{
	transform->SetScale(0.48f, 0.48f);
}

void EndButton::OnMouseExit()
{
	transform->SetScale(0.45f, 0.45f);
}
