#include "stdafx.h"
#include "Arrow.h"

Arrow::Arrow() 
	: GameObject(L"resources/image/arrow_1.png")
{
}

Arrow::~Arrow()
{
}

void Arrow::Update()
{
	Move();
}

void Arrow::Move()
{
	
}