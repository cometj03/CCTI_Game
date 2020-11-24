#pragma once
#include "stdafx.h"

//컴포넌트 객체들의 부모 클래스입니다.
//솔직히 이 프레임워크 내에서는 거의 사용되지 않습니다.
class Component
{
public:
	Component();
	virtual ~Component();

public:

	virtual void Initialize() {};
	virtual void Update() {};
	virtual void Uninitialze() {};

public:
	bool isActive;
};

