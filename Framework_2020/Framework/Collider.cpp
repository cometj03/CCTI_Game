#include "stdafx.h"
#include "Collider.h"

Collider::Collider(GameObject* target)
	:target(target),transform(target->transform)
{
}


Collider::AABBBox::AABBBox() : leftTop(), rightBottom()
{
}

Collider::AABBBox::AABBBox(const AABBBox& box)
{
	this->leftTop = box.leftTop;
	this->rightBottom = box.rightBottom;
}

Collider::AABBBox::AABBBox(const Vector2& size) :leftTop(-size * 0.5f), rightBottom(size * 0.5f)
{

}

Collider::AABBBox::AABBBox(float width, float height) : leftTop((-0.5f)* width, (-0.5f)* height), rightBottom(width * 0.5f, height * 0.5f)
{
}

Collider::AABBBox::AABBBox(const Vector2& leftTop, const Vector2& rightBottom) : leftTop(leftTop), rightBottom(rightBottom)
{
}

Collider::AABBBox::AABBBox(float l, float t, float r, float b)
	: leftTop(l, t), rightBottom(r, b)
{
}

Collider::Circle::Circle()
{
	this->center.x = 0.0f;
	this->center.y = 0.0f;
	this->radius = 0.0f;
}

Collider::Circle::Circle(const Circle& circle)
{
	this->center = circle.center;
	this->radius = circle.radius;
}

Collider::Circle::Circle(float radius)
{
	this->center.x = 0.0f;
	this->center.y = 0.0f;
	this->radius = radius;
}

Collider::Circle::Circle(const Vector2& center, float radius)
{
	this->center = center;
	this->radius = radius;
}

Collider::Circle::Circle(float x, float y, float radius)
{
	this->center.x = x;
	this->center.y = y;
	this->radius = radius;
}
