#include "stdafx.h"
#include "CircleCollider.h"
#include "InputManager.h"
#include "Camera.h"

CircleCollider::CircleCollider(GameObject* gameObject, const Circle& circle)
	:Collider(gameObject), boundingCircle(circle)
{
}

CircleCollider::CircleCollider(GameObject* gameObject, float radius, const Vector2& center)
	: Collider(gameObject), boundingCircle(center, radius)
{
}

CircleCollider::CircleCollider(GameObject* gameObject, float x, float y, float radius)
	: Collider(gameObject), boundingCircle(x, y, radius)
{
}

Collider::Circle CircleCollider::GetTransformedCircle()
{
	return Circle(boundingCircle.center + transform->position, boundingCircle.radius);
}

bool CircleCollider::isMouseOn()
{
	Vector2 v((float)InputManager::GetMouseX(), (float)InputManager::GetMouseY());
	return boundingCircle.radius > (Camera::ScreenPositionToWorld(v) - GetTransformedCircle().center).magnitude();
}
