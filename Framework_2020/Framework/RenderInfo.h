#pragma once
#include "D2DApp.h"
#include "Component.h"
#include "Transform.h"


class RenderInfo :
	public Component
{
public:
	RenderInfo();
	RenderInfo(Sprite* startSprite, float alpha = 1.0f);
	virtual ~RenderInfo() {}
protected:

	Sprite* currentSprite;
	float alpha;
	bool initialized;
	int width, height;

public:
	Sprite* GetCurrentSprite();
	float GetAlpha();
	bool GetInitialized();
	virtual int GetWidth();
	virtual int GetHeight();
	virtual D2D1_RECT_F* GetSourceRect();
	virtual void Update() {}
	virtual void UpdateRenderInfo() {}
	virtual void Render(D2DApp* d2dApp, Transform* transform, Vector2 screenPosition);
	void BasicRender(ID2D1RenderTarget* renderTarget, Transform* transform, D2D1_RECT_F* sourceRect, Vector2 screenPosition);
	
	Vector2 ComputeWorldPosition(Vector2 screenSize, Transform* transform, Vector2 cameraPosition);
	Vector2 ComputeUIPosition(Transform* transform);
};

