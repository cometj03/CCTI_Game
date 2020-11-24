#pragma once
#include "stdafx.h"
#include "WinApp.h"

//DirectX 객체입니다.

struct Sprite {
	const wchar_t* uri;
	ID2D1Bitmap* bitmap;
};

class D2DApp
{
public:
	D2DApp(WinApp* winApp);
private:
	WinApp* winApp;

public:
	//초기화, 정리를 담당하는 함수입니다.
	bool Initialize();
	void Uninitialize();

private:
	//Direct2D에서 사용할 여러 자원을 생성합니다.
	HRESULT CreateDeviceIndependentResources();
	HRESULT CreateDeviceResources();
	void DiscardDeviceResources();
	void DiscardDeviceIndependentResources();

public:
	//테스트용 함수입니다.
	ID2D1Bitmap* example;
	void Render();

	//렌더와 시작, 끝에 호출하는 함수입니다.
	void BeginRender();
	void EndRender();

	//비트맵을 로드합니다. RenderingManager에서도 사용합니다.
	HRESULT LoadBitmapFromFile(PCWSTR uri, UINT destinationWidth, UINT destinationHeight, ID2D1Bitmap** bitmap);

private:
	//Direct2D 자원 객체들입니다.
	ID2D1Factory* factory;
	IWICImagingFactory* wicFactory;
	ID2D1HwndRenderTarget* renderTarget;
	IDWriteFactory* dwriteFactory;
	
public:
	ID2D1HwndRenderTarget* GetRenderTarget();
	IWICImagingFactory* GetImagingFactory();
	ID2D1Factory* GetFactory();
	IDWriteFactory* GetDwriteFactory();
};

