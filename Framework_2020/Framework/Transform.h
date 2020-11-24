#pragma once
#include "Component.h"
#include "Vector2.h"

//게임 오브젝트의 변형 정보를 저장합니다.
//위치정보, 회전정보, 크기 정보를 저장합니다.
//(position, rotation, scale)
class Transform :
	public Component
{
public:
	Transform(Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2(1.0f, 1.0f));
	virtual ~Transform();

public:
	//실제로는 사용되지 않는 함수입니다.
	virtual void Update() {};

	//위치 ,회전 ,크기
	Vector2 position;			//위치정보 (x,y)
	float rotatingAngle;	//회전 각도
	Vector2 scale;			//크기

	//각 변환에 대한 기준점입니다.
	Vector2 positioningCenter;	//위치 지정 기준(기본 값은 이미지 정가운데)
	Vector2 rotatingCenter;		//회전축
	Vector2 scalingCenter;		//크기 변환축

public:
	//Setter 함수
	void SetPosition(float x, float y);
	void SetPosition(const Vector2& v);
	void SetRotation(float angle);
	void SetScale(float x, float y);
	void SetScale(const Vector2& v);
};

