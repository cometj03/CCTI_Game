#include "func.h"

// 3  2  1  0
// 4
// 5
// 6
// 7

int map[MAP_SIZE + 1][MAP_SIZE + 1] =
{
	{ 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 }
};

int whereArrow = 3, oldArrow;
bool isRunning = true;

int main()
{
	char input;
	CursorView(0);
	PrintMap(map);
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
				if (arrow < 7 && arrow >= 3)
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
			PrintArrow(whereArrow, oldArrow);

		}
		else if (input == 'q' || input == 'Q' || input == SPACE) {
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
	PrintMap(map);
}

void Switch_Color(int arrow) {
	switch (arrow)
	{
	case 0: case 1:case 2:
		for (int i = 0; i < 3; i++) {
			int tmp = map[i][MAP_SIZE - arrow - 1];
			tmp = tmp == 1 ? 0 : 1;
			map[i][MAP_SIZE - arrow - 1] = tmp;
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++) {
			int tmp = map[i][i];
			tmp = tmp == 1 ? 0 : 1;
			map[i][i] = tmp;
		}
		break;
	case 4: case 5: case 6:
		for (int i = 0; i < 3; i++) {
			int tmp = map[arrow - MAP_SIZE - 1][i];
			tmp = tmp == 1 ? 0 : 1;
			map[arrow - MAP_SIZE - 1][i] = tmp;
		}
		break;
	case 7:
		for (int i = 0; i < 3; i++) {
			int tmp = map[i][MAP_SIZE - i - 1];
			tmp = tmp == 1 ? 0 : 1;
			map[i][MAP_SIZE - i - 1] = tmp;
		}
	}
	PrintMap(map);
}

