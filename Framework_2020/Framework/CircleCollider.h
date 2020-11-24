#pragma once
#include "Collider.h"

//원 형태의 충돌체를 나타냅니다.

class CircleCollider :
	public Collider
{
public:
	Circle boundingCircle;
public:
	CircleCollider(GameObject* gameObject, const Circle& circle);
	CircleCollider(GameObject* gameObject, float radius, const Vector2& center = Vector2());
	CircleCollider(GameObject* gameObject, float x, float y, float radius);

public:
	Circle GetTransformedCircle();
	bool isMouseOn();
};

