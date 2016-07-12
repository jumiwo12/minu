// 1 지점에서 출발하여 2번 지점으로 탈출하는 경로를 찾아 순서대로 출력한다
#include <stdio.h>
#include <Windows.h>

void print_unit(char map[10][10]);
int judgment();
void shift(char map[10][10]);
int x = 1, y = 1;

int main(int argc, char * argv[]) {
	char map[10][10] = { {1,1,1,1,1,1,1,1,1,1}, 
						 {1,0,0,0,0,0,0,0,0,1},
					     {1,0,0,1,0,1,0,1,0,1},
					     {1,1,1,1,1,1,0,1,0,1},
					     {1,0,0,0,0,0,0,1,0,1},
					     {1,0,0,1,0,1,1,1,1,1},
					     {1,0,1,1,0,0,0,0,0,1},
					     {1,0,0,0,1,0,1,1,1,1},
					     {1,0,1,0,1,0,0,0,0,1},
						 {1,1,1,1,1,1,1,1,1,1} };
	while (1) {
		if (judgment() == 1) break;
		print_unit(map);
		shift(map);
	}
	print_unit(map);
	printf("GOAL~!!\n");
	system("pause");
}

void print_unit(char map[10][10]) {
	Sleep(500);
	system("cls");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == y&&j == x) printf("▽");
			else if (i == 1 && j == 1) printf("①");
			else if (i == 8 && j == 8) printf("②");
			else {
				if (map[i][j] == 1) printf("■");
				else printf("  ");
			}
		}
		printf("\n");
	}
}
int judgment() {
	if (x == 8 && y == 8) return 1;
}
void shift(char map[10][10]) {
	if (judgment() == 1) return;
	if (map[y + 1][x] == 0) {
		y++;
		map[y][x] = 2;
	}
	else if (map[y][x + 1] == 0) {
		x++;
		map[y][x] = 2;
	}
	else if (map[y][x - 1] == 0) {
		x--;
		map[y][x] = 2;
	}
	else if (map[y - 1][x] == 0) {
		y--;
		map[y][x] = 2;
	}
	else if (map[y + 1][x] == 2) {
		y++;
		map[y][x] = 3;
	}
	else if (map[y][x + 1] == 2) {
		x++;
		map[y][x] = 3;
	}
	else if (map[y][x - 1] == 2) {
		x--;
		map[y][x] = 3;
	}
	else if (map[y - 1][x] == 2) {
		y--;
		map[y][x] = 3;
	}
}