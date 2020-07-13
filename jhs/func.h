#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define MAP_SIZE 3
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32

void gotoxy(int x, int y);
void CursorView(char show);

void PrintMap(int(&map)[MAP_SIZE + 1][MAP_SIZE + 1]);
void PrintArrow(int arrow_pos, int old_pos);

void Switch_One(int(&map)[MAP_SIZE + 1][MAP_SIZE + 1], int i);
void Switch_Color(int(&map)[MAP_SIZE + 1][MAP_SIZE + 1], int arrow);

void ArrowCursorPos(int num);