#include "stdafx.h"
#include "RenderInfo.h"
#include "Framework.h"

RenderInfo::RenderInfo()
	: Component(), currentSprite(nullptr), alpha(1.0f), initialized(false), width(0), height(0)
{
}

RenderInfo::RenderInfo(Sprite* startSprite, float alpha)
	: Component(), currentSprite(startSprite), alpha(alpha), initialized(true)
{
	//Sprite 크기 받아옴
	if (startSprite)
	{
		if (startSprite->bitmap)
		{
			D2D1_SIZE_U size = startSprite->bitmap->GetPixelSize();
			width = size.width;
			height = size.height;
		}
		else
		{
			RenderInfo();
		}
	}
	else
	{
		RenderInfo();
	}
}

Sprite* RenderInfo::GetCurrentSprite()
{
	return currentSprite;
}

float RenderInfo::GetAlpha()
{
	return alpha;
}

bool RenderInfo::GetInitialized()
{
	return initialized;
}

int RenderInfo::GetWidth()
{
	return width;
}

int RenderInfo::GetHeight()
{
	return height;
}

D2D1_RECT_F* RenderInfo::GetSourceRect()
{
	return nullptr;
}

void RenderInfo::Render(D2DApp* d2dApp, Transform* transform, Vector2 screenPosition)
{
	if (!d2dApp)
	{
		printf("RenderInfo::Render: d2dApp이 없습니다.\n");
		return;
	}

	ID2D1HwndRenderTarget* renderTarget = d2dApp->GetRenderTarget();
	if (!renderTarget)
	{
		printf("RenderInfo::Render 실패, 렌더타겟이 없습니다.\n");
		return;
	}
	BasicRender(renderTarget, transform, nullptr, screenPosition);
}

void RenderInfo::BasicRender(ID2D1RenderTarget* renderTarget, Transform* transform, D2D1_RECT_F* sourceRect, Vector2 screenPosition)
{
	if (!renderTarget)
	{
		printf("RenderInfo::Render 실패, 렌더타겟이 없습니다.\n");
		return;
	}
	if (!transform)
	{
		printf("RenderInfo::Render: transform이 주어지지 않았습니다.\n");
		return;
	}

	if (!currentSprite || !currentSprite->bitmap)
	{
		printf("RenderInfo::Render 실패, 스프라이트가 없습니다.\n");
		return;
	}
	//D2D1_SIZE_U size;
	//size = currentSprite->bitmap->GetPixelSize();
	Vector2 size;
	size.x = (float)GetWidth();
	size.y = (float)GetHeight();

	Point positioningCenter;
	positioningCenter.x = screenPosition.x;
	positioningCenter.y = screenPosition.y;

	D2D1_RECT_F rect;
	rect.left = positioningCenter.x - size.x * 0.5f;//* o->scale.x;
	rect.top = positioningCenter.y - size.y * 0.5f;// *o->scale.y;
	rect.right = positioningCenter.x + size.x * 0.5f;// *o->scale.x;
	rect.bottom = positioningCenter.y + size.y * 0.5f;// *o->scale.y;

	Point scalingCenter;
	scalingCenter.x = positioningCenter.x + transform->scalingCenter.x;
	scalingCenter.y = positioningCenter.y + transform->scalingCenter.y;

	Point rotatingCenter;
	rotatingCenter.x = positioningCenter.x + transform->rotatingCenter.x;
	rotatingCenter.y = positioningCenter.y + transform->rotatingCenter.y;

	renderTarget->SetTransform(
		D2D1::Matrix3x2F::Scale(
			transform->scale.x,
			transform->scale.y,
			scalingCenter)
		* D2D1::Matrix3x2F::Rotation(
			transform->rotatingAngle * RADTOEULER,
			rotatingCenter
		));
	renderTarget->DrawBitmap(currentSprite->bitmap, &rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, sourceRect);


}

Vector2 RenderInfo::ComputeWorldPosition(Vector2 screenSize, Transform* transform, Vector2 cameraPosition)
{
	return Vector2(
		transform->position.x - transform->positioningCenter.x - cameraPosition.x + screenSize.x * 0.5f,
		transform->positioningCenter.y - transform->position.y + screenSize.y * 0.5f + cameraPosition.y
	);
}

Vector2 RenderInfo::ComputeUIPosition(Transform* transform)
{
	return Vector2(
		transform->position.x - transform->positioningCenter.x,
		transform->position.y - transform->positioningCenter.y
	);
}
