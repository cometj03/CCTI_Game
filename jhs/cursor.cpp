#include "func.h"

void ArrowCursorPos(int num) {
	switch (num)
	{
	case 0:
		gotoxy(7, 0); break;
	case 1:
		gotoxy(4, 0); break;
	case 2:
		gotoxy(1, 0); break;
	case 3:
		gotoxy(0, 0); break;
	case 4:
		gotoxy(0, 1); break;
	case 5:
		gotoxy(0, 3); break;
	case 6:
		gotoxy(0, 5); break;
	case 7:
		gotoxy(0, 6); break;
	}
}

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}