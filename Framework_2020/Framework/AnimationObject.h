#pragma once
#include "GameObject.h"
#include "AnimationInfo.h"
#include "ListAnimation.h"
#include "SheetAnimation.h"
#include "AABBCollider.h"
#include "CircleCollider.h"

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

