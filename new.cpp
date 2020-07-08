#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define MAP_SIZE 4
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int map[MAP_SIZE + 1][MAP_SIZE + 1] =
{
	{ 1, 0, 0, 0},
	{ 0, 0, 0, 0},
	{ 0, 0, 0, 0}
};

void PrintMap();
void PrintArrow();
void Switch_One(int i);
void Switch_Color(int arrow);
void ArrowCursorPos(int num);
void gotoxy(int x, int y);
void CursorView(char show);

int whereArrow = 4, oldArrow;
bool isRunning = true;
bool chance = true;//치트 사용 제한 //todo

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
				if (arrow <= 3 && arrow > -1)
					arrow -= 1;
				else if (arrow > 3)
					arrow = 2;
				break;
			case DOWN:
				if (arrow < 8 && arrow >= 3)
					arrow += 1;
				else if (arrow < 3)
					arrow = 4;
				break;
			case UP:
				// TODO
				if (arrow > 3)
					arrow -= 1;
				break;
			}

			whereArrow = arrow;
			PrintArrow();

		}
		else if (input == 'q' || input == 'Q' || input == 32) {
			Switch_Color(whereArrow);
		}
		else if (input >= 49 && input <= 57) {		//change
			Switch_One(input - 49);
		}
	}
}

void Switch_One(int i){
	if (map[i / MAP_SIZE][i % MAP_SIZE] == 0)	//map[(i-1)/MAP_SIZE][(i-1)%MAP_SIZE]
		map[i / MAP_SIZE][i % MAP_SIZE] = 1;
	else
		map[i / MAP_SIZE][i % MAP_SIZE] = 0;
	PrintMap();
}

void Switch_Color(int arrow) {
	switch (arrow)
	{
	case -1:case 0:case 1:case 2:
		for (int i = 0; i < MAP_SIZE; i++) {
			int tmp = map[i][MAP_SIZE - arrow - 2];
			tmp = tmp == 1 ? 0 : 1;
			map[i][MAP_SIZE - arrow - 2] = tmp;
		}
		break;
	case 3://diagonal line
		for (int i = 0; i < 4; i++) {
			int tmp = map[i][i];
			tmp = tmp == 1 ? 0 : 1;
			map[i][i] = tmp;
		}
		break;
	case 4: case 5: case 6:case 7:
		for (int i = 0; i < MAP_SIZE; i++) {
			int tmp = map[arrow - MAP_SIZE][i];
			tmp = tmp == 1 ? 0 : 1;
			map[arrow - MAP_SIZE][i] = tmp;
		}
		break;
	case 8://diagonal line
		for (int i = 0; i < 4; i++) {
			int tmp = map[i][MAP_SIZE - i - 1];
			tmp = tmp == 1 ? 0 : 1;
			map[i][MAP_SIZE - i - 1] = tmp;
		}
	}
	PrintMap();
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
	// 3  2  1  0  -1 
	// 4
	// 5
	// 6
	// 7
	ArrowCursorPos(oldArrow);
	printf("  ");

	ArrowCursorPos(whereArrow);
	if (whereArrow == 3)
		printf("↘");
	else if (whereArrow == 8)
		printf("↗");
	else if (whereArrow < 3)
		printf("↓");
	else
		printf("→");
	gotoxy(15, 5);
	printf("%d", whereArrow);
}

void ArrowCursorPos(int num) {
	switch (num)
	{
	case -1:
		gotoxy(10, 0); break;
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
		gotoxy(0, 7); break;
	case 8:
		gotoxy(0, 8); break;
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