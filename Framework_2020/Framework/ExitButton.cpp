#include "stdafx.h"
#include "ExitButton.h"

ExitButton::ExitButton(const wchar_t* uri)
	: Button(uri)
{
}

void ExitButton::OnClick()
{
	std::cout << "Exit\n";
	PostQuitMessage(0);
}
