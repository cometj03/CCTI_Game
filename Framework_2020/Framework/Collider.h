#pragma once
#include "Transform.h"
#include "GameObject.h"
class Collider
{
public:
	struct AABBBox //AABB 충돌처리
	{
		Vector2 leftTop;			//(0,0)을 기준으로 한 좌상단 꼭지점의 포지션값입니다. 상자의 중심을 0,0으로 두었을 경우 음수 값을 가지게 됩니다.
		Vector2 rightBottom;		//(0,0)을 기준으로 한 우하단 꼭지점의 포지션값입니다. 상자의 중심을 0,0으로 두었을 경우 양수 값을 가지게 됩니다.

		AABBBox();
		AABBBox(const AABBBox& box);
		AABBBox(const Vector2& size);
		AABBBox(float width, float height);
		AABBBox(const Vector2& leftTop, const Vector2& rightBottom);
		AABBBox(float left, float top, float right, float bottom);
	};
	struct Circle //center값은 transform.position을 원점으로한 거리입니다.
	{
		Vector2 center;			//기본적으로 0,0
		float radius;			//원의 반지름

		Circle();
		Circle(const Circle& circle);
		Circle(float radius);
		Circle(const Vector2& center, float radius);
		Circle(float x, float y, float radius);
	};
public:
	Collider(GameObject* target);
public:
	GameObject* target;
	Transform* transform;
};

