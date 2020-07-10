#include "func.h"

int current_arrow_pos = 3;

void PrintMap(int(&map)[MAP_SIZE + 1][MAP_SIZE + 1]) {
	system("cls");
	PrintArrow(current_arrow_pos, current_arrow_pos);
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

void PrintArrow(int arrow_pos, int old_pos) {

	current_arrow_pos = arrow_pos;

	ArrowCursorPos(old_pos);	// 이전 화살표를 지움
	printf("  ");

	ArrowCursorPos(arrow_pos);
	if (arrow_pos == 3)
		printf("↘");
	else if (arrow_pos == 7)
		printf("↗");
	else if (arrow_pos < 3)
		printf("↓");
	else
		printf("→");
	gotoxy(10, 5);
	printf("%d", arrow_pos);	// 새 화살표 출력
}