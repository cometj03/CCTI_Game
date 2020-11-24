#pragma once
//stdafx.h 미리 컴파일된 헤더 파일입니다.
//미리 컴파일된 헤더: 자주 사용하는 헤더 파일을 미리 컴파일하여 저장하고, 다음 컴파일 속도를 올려줍니다.
//그 외에도 모든 cpp 파일에서 사용할 헤더를 묶어서 정리하는 이점도 있습니다.
//따라서 여러 헤더 파일과 라이브러리 파일을 여기서 인클루드 합니다.

//Windows.h, 윈도우 창과 여러 기본 함수를 사용하기 위한 헤더 파일입니다.
#include <Windows.h>

//C++ 기본 헤더 파일입니다.
#include <iostream>		//입출력(콘솔 등)
#include <string>		//문자열
#include <list>			//리스트
#include <vector>		//벡터
#include <random>		//랜덤

//다이렉트X 관련 헤더 파일입니다.
#include <d2d1.h>
#include <d2d1helper.h>

//COM 오브젝트를 사용하기 위한 헤더파일입니다.
#include <wincodec.h>

//FONT를 사용하기 위한 DirectWrite 헤더파일입니다.
#include <dwrite.h>

//SOUND를 사용하기 위한 Xaudio2, MF관련 헤더파일입니다.
#include <xaudio2.h>
#include <mfapi.h>		//wmf
#include <mfidl.h>
#include <mfreadwrite.h>

//메모리 누수 체크용 헤더파일입니다.
//디버깅 모드에서 아래 CheckMemoryLeak.h의 주석을 해제하면 사용 가능합니다.
//main 함수 마지막에 _CrtDumpMemoryLeaks(); 추가해주면 디버깅 후 출력 창에 누수된 메모리를 확인할 수 있습니다.
//#include "CheckMemoryLeak.h"


//아래는 라이브러리를 포함하기 위한 코드입니다.

//다이렉트X, 윈도우 관련 라이브러리
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "WindowsCodecs.lib")
#pragma comment(lib, "Winmm.lib")

//Font: DirectWrite 라이브러리
#pragma comment(lib, "Dwrite.lib")

//SOUND: Xaudio2, MF 라이브러리
#pragma comment (lib, "Xaudio2.lib")
#pragma comment (lib, "mfreadwrite.lib")
#pragma comment (lib, "mfplat.lib")
#pragma comment (lib, "mfuuid")

//디버그 창에서는 콘솔을 띄우고, 릴리즈에서는 콘솔을 띄우지 않기 위한 구문입니다.
#ifndef _DEBUG
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#else
#    pragma comment(linker, "/SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup")
#endif

//SAFE_RELEASE, SAFE_DELETE와 기타 매크로 함수입니다.
#define SAFE_RELEASE(p) { if(p){p->Release();} p=NULL; }
#define SAFE_DELETE(p) {if(p!=nullptr){delete(p);} p=nullptr; }
#define PI 3.141592653589793f
#define RADTOEULER -180.0f/PI

//Direct2D에 구현된 구조체를 한번 더 typedef해주었습니다.
typedef D2D1_POINT_2F Point;