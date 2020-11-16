#include "stdafx.h"
#include "CollisionManager.h"

CollisionManager::~CollisionManager()
{
	//Collider의 instance는 게임오브젝트에서 각자 삭제처리 해주는 것으로 간주합니다.
	aabbList.clear();
}

AABBCollider* CollisionManager::PushBackCollider(AABBCollider* col)
{
	aabbList.push_back(col);
	gameObjectList.push_back(col->target);
	return col;
}

CircleCollider* CollisionManager::PushBackCollider(CircleCollider* col)
{
	circleList.push_back(col);
	gameObjectList.push_back(col->target);
	return col;
}

void CollisionManager::RemoveGameObject(GameObject* g)
{
	gameObjectList.remove(g);
	std::list<AABBCollider*>::iterator iter = aabbList.begin();
	for (; iter != aabbList.end(); iter++)
	{
		if ((*iter)->target == g)
		{
			aabbList.erase(iter);
			break;
		}
	}

	std::list<CircleCollider*>::iterator iter2 = circleList.begin();
	for (; iter2 != circleList.end(); iter2++)
	{
		if ((*iter2)->target == g)
		{
			circleList.erase(iter2);
			break;
		}
	}
}

void CollisionManager::Update()
{
	//충돌 처리
	//aabb<->aabb
	for (std::list<AABBCollider*>::iterator i = aabbList.begin();
		i!=aabbList.end(); i++)
	{
		std::list<AABBCollider*>::iterator j = i;
		j++;
		for (; j != aabbList.end(); j++)
		{
			if(Intersected((*i),(*j)))
			{
				(*i)->target->OnCollision((*j)->target);
				(*j)->target->OnCollision((*i)->target);
			}
		}
	}

	//circle<->circle
	for (std::list<CircleCollider*>::iterator i = circleList.begin();
		i != circleList.end(); i++)
	{
		std::list<AABBCollider*>::iterator j = aabbList.begin();
		for (; j != aabbList.end(); j++)
		{
			if (Intersected((*j), (*i)))
			{
				(*i)->target->OnCollision((*j)->target);
				(*j)->target->OnCollision((*i)->target);
			}
		}
	}

	//circle<->aabb
	for (std::list<CircleCollider*>::iterator i = circleList.begin();
		i != circleList.end(); i++)
	{
		std::list<CircleCollider*>::iterator j = i;
		j++;
		for (; j != circleList.end(); j++)
		{
			if (Intersected((*i), (*j)))
			{
				(*i)->target->OnCollision((*j)->target);
				(*j)->target->OnCollision((*i)->target);
			}
		}
	}
}

bool CollisionManager::Intersected(AABBCollider* a, AABBCollider* b)
{
	float aLeft, bLeft;
	float aRight, bRight;
	float aTop, bTop;
	float aBottom, bBottom;
	aLeft = a->boundingBox.leftTop.x * a->transform->scale.x
		+ a->transform->position.x;
	aRight = a->boundingBox.rightBottom.x * a->transform->scale.x
		+ a->transform->position.x;
	aTop = a->boundingBox.leftTop.y * a->transform->scale.y
		+ a->transform->position.y;
	aBottom = a->boundingBox.rightBottom.y * a->transform->scale.y
		+ a->transform->position.y;

	bLeft = b->boundingBox.leftTop.x * b->transform->scale.x
		+ b->transform->position.x;
	bRight = b->boundingBox.rightBottom.x * b->transform->scale.x
		+ b->transform->position.x;
	bTop = b->boundingBox.leftTop.y * b->transform->scale.y
		+ b->transform->position.y;
	bBottom = b->boundingBox.rightBottom.y * b->transform->scale.y
		+ b->transform->position.y;

	/*std::cout << a->boundingBox.leftTop.x << " " << a->boundingBox.rightBottom.x
		<< " " << a->boundingBox.leftTop.y << " " << a->boundingBox.rightBottom.y << "\n";
*/
	return
		!(
		(aRight < bLeft) || (bRight < aLeft) ||
			(aBottom > bTop) || (bBottom > aTop)
			);
}

bool CollisionManager::Intersected(CircleCollider* a, CircleCollider* b)
{
	Vector2 centerVector = b->GetTransformedCircle().center - a->GetTransformedCircle().center;					//중심을 잇는 벡터
	float distance = centerVector.DotProduct(centerVector);		//자기 자신의 내적==제곱
	return distance < ((a->boundingCircle.radius + b->boundingCircle.radius) * (a->boundingCircle.radius + b->boundingCircle.radius));	//거리비교
}

bool CollisionManager::Intersected(AABBCollider* a, CircleCollider* b)
{
	Vector2 circleDistance;
	Collider::AABBBox abox = a->GetTransformedBox();
	Collider::Circle bcircle = b->GetTransformedCircle();
	circleDistance.x = (abox.rightBottom.x + abox.leftTop.x) * 0.5f - bcircle.center.x;
	circleDistance.y = (abox.rightBottom.y + abox.leftTop.y) * 0.5f - bcircle.center.y;
	Vector2 halfBox = Vector2((abox.rightBottom - abox.leftTop) * 0.5f);

	circleDistance.x *= (circleDistance.x >= 0) ? 1.0f : -1.0f;
	circleDistance.y *= (circleDistance.y >= 0) ? 1.0f : -1.0f;

	if (circleDistance.x > (halfBox.x + bcircle.radius)) { return false; }
	if (circleDistance.y > (halfBox.y + bcircle.radius)) { return false; }

	if (circleDistance.x <= halfBox.x) { return true; }
	if (circleDistance.y <= halfBox.y) { return true; }

	Vector2 corner = circleDistance - halfBox;

	return (corner.DotProduct(corner) <= (bcircle.radius * bcircle.radius));
}
	