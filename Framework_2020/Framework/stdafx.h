#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <random>

//다이렉트x 관련 헤더
#include <d2d1.h>
#include <d2d1helper.h>

//COM
#include <wincodec.h>

//FONT
#include <dwrite.h>

//SOUND
#include <xaudio2.h>
#include <mfapi.h>		//wmf
#include <mfidl.h>
#include <mfreadwrite.h>

//메모리 누수 체크용
//main 함수 마지막에 _CrtDumpMemoryLeaks(); 추가해주면 확인 가능
//#include "CheckMemoryLeak.h"

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "WindowsCodecs.lib")
#pragma comment(lib, "Winmm.lib")//이거

//Font
#pragma comment(lib, "Dwrite.lib")

//SOUND
#pragma comment (lib, "Xaudio2.lib")
#pragma comment (lib, "mfreadwrite.lib")
#pragma comment (lib, "mfplat.lib")
#pragma comment (lib, "mfuuid")


#ifndef _DEBUG
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#else
#    pragma comment(linker, "/SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup")
#endif


#define SAFE_RELEASE(p) { if(p){p->Release();} p=NULL; }
#define SAFE_DELETE(p) {if(p!=nullptr){delete(p);} p=nullptr; }
#define PI 3.141592653589793f
#define RADTOEULER -180.0f/PI

typedef D2D1_POINT_2F Point;