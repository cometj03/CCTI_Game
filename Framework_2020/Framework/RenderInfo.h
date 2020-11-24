#pragma once
#include "D2DApp.h"
#include "Component.h"
#include "Transform.h"

//Render 정보를 저장합니다.
//원래 이름은 Renderer였습니다. Renderer가 더 잘 어울리는 이름 같습니다.
//Render할 것의 정보를 저장하고, Render합니다.

//기본적으로 Sprite 정보를 저장하지만, 필요에 따라 상속받아 사용할 수 있습니다.
//currentSprite에 저장된 스프라이트가 출력됩니다.
//혹은 Render함수도 상속받아 수정할 수있습니다.
//AnimationRenderInfo, FontRenderInfo 등의 자식 클래스가 존재합니다.

class RenderInfo :
	public Component
{
public:
	RenderInfo();
	RenderInfo(Sprite* startSprite, float alpha = 1.0f);
	virtual ~RenderInfo() {}
protected:
	//현재 출력할 Sprite를 저장합니다.
	Sprite* currentSprite;

	//초기화되었는지를 저장합니다.
	//이미지나 폰트 등을 로드한 후 true를 바꿔줘야 사용이 가능합니다.
	bool initialized;

	//기본 이미지의 가로, 세로를 저장합니다.
	int width, height;

public:
	//투명도를 저장합니다.
	float alpha;

public:
	//Getter 함수
	Sprite* GetCurrentSprite();
	float GetAlpha();

	bool GetInitialized();
	virtual int GetWidth();
	virtual int GetHeight();

	virtual D2D1_RECT_F* GetSourceRect();

	//Update입니다. 사실 잘 사용하진 않습니다.
	virtual void Update() {}

	//RenderInfo의 Render시마다 호출하여 사용합니다.
	//애니메이션의 프레임 업데이트 등에 사용됩니다.
	virtual void UpdateRenderInfo() {}

	//RenderingManager 클래스에서 실제 Render를 수행할 떄 사용되는 함수입니다.
	virtual void Render(D2DApp* d2dApp, Transform* transform, Vector2 screenPosition);

	//Sprite를 렌더합니다.
	void BasicRender(ID2D1RenderTarget* renderTarget, Transform* transform, D2D1_RECT_F* sourceRect, Vector2 screenPosition);
	
	//Render를 위한 내부 함수입니다.
	//Transform을 적용합니다.
	Vector2 ComputeWorldPosition(Vector2 screenSize, Transform* transform, Vector2 cameraPosition);
	Vector2 ComputeUIPosition(Transform* transform);
};

