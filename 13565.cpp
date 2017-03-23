#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;


char map[1002][1002];
bool visit[1002][1002];
int m, n;
int flag = 0;
int recur(int x, int y) {
	if (flag) {
		return 1;
	}
	if (x == m - 1) {
		flag = 1;
		return 1;
	}
	if (x + 1 < m) {
		if (map[x + 1][y] == '0'&&visit[x+1][y]==0) {
			visit[x + 1][y] = true;
			recur(x + 1, y);
		}
	}
	if (x - 1 >= 0) {
		if (map[x - 1][y] == '0'&&visit[x - 1][y] == 0) {
			visit[x - 1][y] = true;
			recur(x - 1, y);
		}
	}
	if (y + 1 < n) {
		if (map[x][y + 1] == '0'&&visit[x][y+1] == 0) {
			visit[x][y+1] = true;
			recur(x, y+1);
		}
	}
	if(y-1>=0){
		if (map[x][y-1] == '0'&&visit[x][y-1] == 0) {
			visit[x][y-1] = true;
			recur(x , y-1);
		}
	}
	return 0;
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf("%s",map[i]);
	}
	for (int i = 0; i < n; i++) {
		if (map[0][i] == '0') {
			visit[0][i] = 1;
			if (recur(0, i)) {
				printf("YES\n");
				return 0;
			}
			for (int p = 0; p < 1000; p++) {
				for (int q = 0; q < 1000; q++) {
					visit[p][q] = 0;
				}
			}
			visit[0][i] = 0;
		}
	}
	printf("NO\n");
}