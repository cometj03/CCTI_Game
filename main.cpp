#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define MAP_SIZE 3
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int map[MAP_SIZE + 1][MAP_SIZE + 1] =
{
	{ 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 }
};

void PrintMap();
void PrintArrow();
void ArrowCursorPos(int num);
void gotoxy(int x, int y);
void CursorView(char show);

int whereArrow = 4, oldArrow;
bool isRunning = true;

int main()
{
	char input;
	CursorView(0);
	PrintMap();
	while (isRunning) {
		fflush(stdin);
		input = _getch();
		if (input == -32) {
			input = _getch();
			int arrow = oldArrow = whereArrow;

			switch (input)
			{
			case LEFT:
				if (arrow < 3)
					arrow += 1;
				break;
			case RIGHT:
				if (arrow <= 3 && arrow > 0)
					arrow -= 1;
				else if (arrow > 3)
					arrow = 2;
				break;
			case DOWN:
				if (arrow < 6 && arrow >= 3)
					arrow += 1;
				else if (arrow < 3)
					arrow = 4;
				break;
			case UP:
				if (arrow > 3)
					arrow -= 1;
				break;
			}
			whereArrow = arrow;
			PrintArrow();
		}
		//PrintMap();
	}

}

void PrintMap() {
	system("cls");
	PrintArrow();
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			gotoxy(j * 3 + 1, i * 2 + 1);
			if (map[i][j] == 0)
				printf("○");
			else if (map[i][j] == 1)
				printf("●");
		}
	}
}

void PrintArrow() {
	// 3  2  1  0
	// 4
	// 5
	// 6
	ArrowCursorPos(oldArrow);
	printf("  ");

	ArrowCursorPos(whereArrow);
	if (whereArrow == 3)
		printf("↘");
	else if (whereArrow < 3)
		printf("↓");
	else
		printf("→");
	gotoxy(10, 5);
	printf("%d", whereArrow);
}

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
	}
}

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}