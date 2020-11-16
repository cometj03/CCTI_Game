#include "stdafx.h"
#include "AABBCollider.h"
#include "InputManager.h"
#include "Camera.h"


AABBCollider::AABBCollider(GameObject* target, float width, float height)
	:Collider(target), boundingBox(width, height)
{
}

AABBCollider::AABBCollider(GameObject* target, Sprite* sprite)
	:Collider(target)
{
	boundingBox.leftTop.x		= (float)(sprite->bitmap->GetPixelSize().width)*(-1.0f) * 0.5f;
	boundingBox.rightBottom.x	= (float)sprite->bitmap->GetPixelSize().width * 0.5f;
	boundingBox.leftTop.y		= (float)sprite->bitmap->GetPixelSize().height * 0.5f;
	boundingBox.rightBottom.y	= (float)(sprite->bitmap->GetPixelSize().height)*(-1.0f) * 0.5f;
}

AABBCollider::AABBCollider(GameObject* target, RenderInfo* renderer)
	:Collider(target)
{
	boundingBox.leftTop.x = (float)(-renderer->GetWidth() * 0.5f);
	boundingBox.rightBottom.x = (float)renderer->GetWidth() * 0.5f;
	boundingBox.leftTop.y = (float)renderer->GetHeight() * 0.5f;
	boundingBox.rightBottom.y = (float)(-renderer->GetHeight() * 0.5f);
}

AABBCollider::AABBCollider(GameObject* target,
	float left, float bottom, float right, float top)
	: Collider(target), boundingBox(left, top, right, bottom)
{
}

AABBCollider::AABBCollider(GameObject* target, const Vector2& size)
	: Collider(target), boundingBox(size)
{
}

AABBCollider::AABBCollider(GameObject* target, const Vector2& leftTop, const Vector2& rightBottom)
	: Collider(target), boundingBox(leftTop, rightBottom)
{
}
//}
//
//bool AABBCollider::Intersected(const AABBBox& other)
//{
//	//절대 교차할 수 없는 경우를 구한 후, 그 역을 반환
//	return !(
//		(boundingBox.rightBottom.x < other.leftTop.x) ||
//		(other.rightBottom.x < boundingBox.leftTop.x) ||
//		(boundingBox.rightBottom.y < other.leftTop.y) ||
//		(other.rightBottom.y < boundingBox.leftTop.y));
//}


AABBCollider::~AABBCollider()
{
}

Collider::AABBBox AABBCollider::GetTransformedBox()
{
	return AABBBox(transform->position + boundingBox.leftTop, transform->position + boundingBox.rightBottom);
}

float AABBCollider::GetWidth()
{
	return boundingBox.rightBottom.x - boundingBox.leftTop.x;
}

float AABBCollider::GetHeight()
{
	return boundingBox.rightBottom.y - boundingBox.leftTop.y;
}

float AABBCollider::GetSquareDiagonal()
{
	return (GetWidth() * GetWidth()) + (GetHeight() * GetHeight());
}

bool AABBCollider::isMouseOn()
{
	Vector2 v = Camera::ScreenPositionToWorld(Vector2((float)InputManager::GetMouseX(), (float)InputManager::GetMouseY()));
	AABBBox b = GetTransformedBox();
	return v.x<b.rightBottom.x&&v.x>b.leftTop.x&&v.y<b.leftTop.y&&v.y>b.rightBottom.y;
}
