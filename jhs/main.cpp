#include "func.h"

/*

일정 턴이 지나면 정해진 곳의 색 바꾸기
변수:일정 턴, 색이 바뀔곳

*/

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

int whereArrow = 3, oldArrow, cnt = 0;
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
		else if (input == 'q' || input == 'Q' || input == SPACE) {	// space bar
			Switch_Color(map, whereArrow);
			cnt++;
		}
		else if (input >= 49 && input <= 57) {		//change
			Switch_One(map, input - 49);
			cnt += 100;
		}
		else if (input == 'x' || input == 'X') {
			printf("%d", cnt);
			isRunning = false;
		}
	}
	
}
