#include <iostream>

using namespace std;

int n;
int board_[11][11];
int max_ = 0;
void crossCnt(int x, int y,int cnt) {
	int i;
	for (i = 1; i <= 4; i++) {
		int t_x = x;
		int t_y = y;
		if (i == 1) {
			t_x--;
			t_y--;
			while(t_x >= 1 && t_y >= 1) {
				if (board_[t_x][t_y] == 1) {
					board_[t_x][t_y] = cnt*10;
				}
				t_x--;
				t_y--;
			}
		}
		else if (i == 2) {
			t_x++;
			t_y--;
			while (t_x <=n && t_y >= 1) {
				if (board_[t_x][t_y] == 1) {
					board_[t_x][t_y] = cnt*10;
				}
				t_x++;
				t_y--;
			}
		}
		else if (i == 3) {
			t_x--;
			t_y++;
			while (t_x >= 1 && t_y <=n) {
				if (board_[t_x][t_y] == 1) {
					board_[t_x][t_y] = cnt*10;
				}
				t_x--;
				t_y++;
			}
		}
		else {
			t_x++;
			t_y++;
			while (t_x <=n && t_y <=n) {
				if (board_[t_x][t_y] == 1) {
					board_[t_x][t_y] = cnt*10;
				}
				t_x++;
				t_y++;
			}
		}
	}
}
void crossOne(int x, int y, int cnt) {
	int i;
	for (i = 1; i <= 4; i++) {
		int t_x = x;
		int t_y = y;
		if (i == 1) {
			t_x--;
			t_y--;
			while (t_x >= 1 && t_y >= 1) {
				if (board_[t_x][t_y] == cnt*10) {
					board_[t_x][t_y] = 1;
				}
				t_x--;
				t_y--;
			}
		}
		else if (i == 2) {
			t_x++;
			t_y--;
			while (t_x <= n && t_y >= 1) {
				if (board_[t_x][t_y] == cnt*10) {
					board_[t_x][t_y] = 1;
				}
				t_x++;
				t_y--;
			}
		}
		else if (i == 3) {
			t_x--;
			t_y++;
			while (t_x >= 1 && t_y <= n) {
				if (board_[t_x][t_y] == cnt*10) {
					board_[t_x][t_y] = 1;
				}
				t_x--;
				t_y++;
			}
		}
		else {
			t_x++;
			t_y++;
			while (t_x <= n && t_y <= n) {
				if (board_[t_x][t_y] == cnt*10) {
					board_[t_x][t_y] = 1;
				}
				t_x++;
				t_y++;
			}
		}
	}
}
void dfs(int x, int y,int count) {
	int next_x = 0;
	int next_y = 0;
	int i, j;
	int ck = 0;
	int cnt = 0;

	board_[x][y] = 3;
	crossCnt(x, y,count);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (board_[i][j] == 1) {
				cnt++;
			}
		}
	}
	if (cnt + count <= max_) {
		return;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == x&&y == j) continue;
			if (board_[i][j] == 1) {
				next_x = i;
				next_y = j;
				dfs(next_x, next_y, count + 1);
				ck = 1;
				
			}
		}
	}
	if (ck == 0) {
		if (max_ < count) {
			max_ = count;
		}
		crossOne(x, y,count);
		board_[x][y] = 1;
		return;
	}
	if (count == 1) {
		crossOne(x, y,count);
	}
	board_[x][y] = 1;
}
int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> board_[i][j];
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (board_[i][j] == 1) {
				dfs(i, j, 1);
			}
		}
	}
	cout << max_ << endl;
	
}
