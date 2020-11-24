#pragma once
//입출력을 나타내는 InputManager클래스 입니다.

//WinApp을 사용합니다.
#include "WinApp.h"

//키가 눌리고 있는 경우를 2, 눌린 경우를 1, 떼어진 경우를 -1로 처리합니다.
//부등호나 등호를 이용하여 계산이 가능합니다.
//true, false처럼 0이 아니면 눌린 상태인 것도 체크 가능합니다.
#define KEYPRESSED 2
#define KEYDOWN 1
#define KEYUP -1


//입력을 담당하는 InputManager 클래스입니다.
//Framework 클래스에서 호출됩니다.
class InputManager
{
	friend class Framework;				
public:
	InputManager();
	~InputManager();
private:
	//WinApp을 사용합니다.
	static WinApp* winApp;			

	//이전에 입력된 값과 현재 입력된 값을 저장합니다.
	//해당 값들을 비교하여 키의 상태를 확인합니다.
	static bool lkey[256], rkey[256];

	//마우스의 위치를 int로 저장합니다.
	static int mX, mY;

public:
	//매 프레임 호출되어 키의 상태를 Update합니다.
	static void UpdateKeyState();

	//게임 구현 중 키 입력을 사용할 때 사용되는 함수들입니다.
	static int GetKeyState(int vk);	//키의 상태를 숫자로 반환합니다.
	static bool GetKeyDown(int vk);	//키가 막 눌린 상태인지를 확인합니다.
	static bool GetKeyPressed(int vk);	//키가 눌리고 있는지를 확인합니다.
	static bool GetKeyUp(int vk);	//키가 막 떼어진 상태인지 확인합니다.

public:
	//마우스의 위치를 확인합니다.
	static int GetMouseX();
	static int GetMouseY();
};

