#include <iostream>
using namespace std;
int map[10][10];

bool ck(int x, int y, int val) {
	for (int i = 1; i <= 9; i++) {
		if (map[i][y] == val) return false;
	}
	for (int i = 1; i <= 9; i++) {
		if (map[x][i] == val) return false;
	}
	if (x >= 1 && x <= 3) {
		if (y >= 1 && y <= 3) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (map[i][j] == val) return false;
				}
			}
		}
		else if (y >= 4 && y <= 6) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 4; j <= 6; j++) {
					if (map[i][j] == val) return false;
				}
			}
		}
		else {
			for (int i = 1; i <= 3; i++) {
				for (int j = 7; j <= 9; j++) {
					if (map[i][j] == val) return false;
				}
			}
		}
	}
	else if (x >= 4 && x <= 6) {
		if (y >= 1 && y <= 3) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (map[i][j] == val) return false;
				}
			}
		}
		else if (y >= 4 && y <= 6) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 4; j <= 6; j++) {
					if (map[i][j] == val) return false;
				}
			}
		}
		else {
			for (int i = 1; i <= 3; i++) {
				for (int j = 7; j <= 9; j++) {
					if (map[i][j] == val) return false;
				}
			}
		}
	}
	else {
		if (y >= 1 && y <= 3) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (map[i][j] == val) return false;
				}
			}
		}
		else if (y >= 4 && y <= 6) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 4; j <= 6; j++) {
					if (map[i][j] == val) return false;
				}
			}
		}
		else {
			for (int i = 1; i <= 3; i++) {
				for (int j = 7; j <= 9; j++) {
					if (map[i][j] == val) return false;
				}
			}
		}
	}
	return true;
}
int recur(int x, int y) {

}


int main()
{
	int start_x, start_y;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				start_x = i;
				start_y = j;
			}
		}
	}
	recur(start_x, start_y);

}