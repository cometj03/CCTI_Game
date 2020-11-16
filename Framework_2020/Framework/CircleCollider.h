#pragma once
#include "Collider.h"
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

