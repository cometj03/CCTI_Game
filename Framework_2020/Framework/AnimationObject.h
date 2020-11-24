#pragma once
#include "GameObject.h"
#include "AnimationInfo.h"
#include "ListAnimation.h"
#include "SheetAnimation.h"
#include "AABBCollider.h"
#include "CircleCollider.h"

//애니메이션 오브젝트 예시 클래스입니다.
//.cpp 파일로 가시면 자세한 설명이 있습니다.

class AnimationObject :
	public GameObject
{
public:
	AnimationObject(AnimationInfo* animinfo);
	~AnimationObject();

public:
	AnimationInfo* animationRenderer;

	ListAnimation* testAnim1;
	SheetAnimation* testAnim2;

	CircleCollider* cc;

	float moveSpeed;
public:
	virtual void Update();
};

