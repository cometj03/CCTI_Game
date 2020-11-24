#pragma once
//메모리 누수 체크용 헤더파일입니다.
//디버깅 모드에서 stdafx.h의 #include "CheckMemoryLeak.h"의 주석을 해제하면 사용 가능합니다.
//main 함수 마지막에 _CrtDumpMemoryLeaks(); 추가해주면 디버깅 후 출력 창에 누수된 메모리를 확인할 수 있습니다.

#include <crtdbg.h>
#if _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif