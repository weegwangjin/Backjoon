#include <iostream>
#include <queue>
using namespace std;

char map[50][50];
int max_ = -1;
int r, c;
int visit[50][50];
int cnt[50][50];
struct node {
	int x, y, step;
};
void bfs(int st, int fi) {
	int ans = 0;
	queue<node> qu;
	qu.push({ st, fi,0 });
	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		int step = qu.front().step;
		qu.pop();
		if (x - 1 >= 0) {
			if (map[x - 1][y] == 'L' && visit[x-1][y]==0) {
				qu.push({ x - 1,y,step+1 });
				visit[x - 1][y] = 1;
			}
		}
		if (x + 1 <= r) {
			if (map[x + 1][y] == 'L' && visit[x+1][y]==0) {
				qu.push({ x + 1,y ,step+1 });
				visit[x + 1][y] = 1;
			}
		}
		if (y - 1 >= 0) {
			if (map[x][y - 1] == 'L' && visit[x][y - 1] == 0) {
				qu.push({ x,y - 1,step+1 });
				visit[x][y - 1] = 1;
			}
		}
		if (y + 1 <= c) {
			if (map[x][y + 1] == 'L' && visit[x][y + 1] == 0) {
				qu.push({ x,y + 1,step+1 });
				visit[x][y + 1] = 1;
			}
		}
		if (max_ < step) max_ = step;
	}
}
/* dfs로 다돌려버리면 시간초과
void dfs(int x, int y,int step) {
	if (cnt[x][y] == 0) cnt[x][y] = step;
	if (cnt[x][y] > step) cnt[x][y] = step;
	if (x - 1 >= 0) {
		if (map[x - 1][y] == 'L' && visit[x - 1][y] == 0) {
			visit[x - 1][y] = 1;
			dfs(x - 1, y, step + 1);
		}
	}
	if (x + 1 <= r) {
		if (map[x + 1][y] == 'L' && visit[x + 1][y] == 0) {
			visit[x + 1][y] = 1;
			dfs(x + 1, y, step + 1);
		}
	}
	if (y - 1 >= 0) {
		if (map[x][y - 1] == 'L' && visit[x][y - 1] == 0) {
			visit[x][y - 1] = 1;
			dfs(x, y - 1, step + 1);
		}
	}
	if (y + 1 <= c) {
		if (map[x][y + 1] == 'L' && visit[x][y + 1] == 0) {
			visit[x][y + 1] = 1;
			dfs(x, y + 1, step + 1);
		}
	}
	visit[x][y] = 0;
} */
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'L') {
				visit[i][j] = 1;
				bfs(i, j);
				for (int p = 0; p < 50; p++) {
					for (int q = 0; q < 50; q++) {
						visit[p][q] = 0;
					}
				}
			}
		}
	}
	cout << max_ << endl;
}