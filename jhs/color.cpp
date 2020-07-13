#include "func.h"



void Switch_One(int(&map)[MAP_SIZE + 1][MAP_SIZE + 1], int i){
	if (map[i / MAP_SIZE][i % MAP_SIZE] == 0)	//map[(i-1)/MAP_SIZE][(i-1)%MAP_SIZE]
		map[i / MAP_SIZE][i % MAP_SIZE] = 1;
	else
		map[i / MAP_SIZE][i % MAP_SIZE] = 0;
	PrintMap(map);
}



void Switch_Color(int(&map)[MAP_SIZE + 1][MAP_SIZE + 1], int arrow) {
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