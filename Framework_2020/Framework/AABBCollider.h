#pragma once
#include "Collider.h"

//AABBBox 형태의 충돌체를 나타냅니다.

class AABBCollider : public Collider
{
public:
	AABBBox boundingBox;
	
	AABBCollider(GameObject* target, float width, float height);
	AABBCollider(GameObject* target, Sprite* sprite);
	AABBCollider(GameObject* target, RenderInfo* renderer);
	AABBCollider(GameObject* target, float left, float bottom, float right, float top);
	AABBCollider(GameObject* target, const Vector2& size);
	AABBCollider(GameObject* target, const Vector2& leftTop, const Vector2& rightBottom);

	~AABBCollider();


	AABBBox GetTransformedBox();
	float GetWidth();
	float GetHeight();
	float GetSquareDiagonal();

	bool isMouseOn();
	bool isMouseOnUI();
};

