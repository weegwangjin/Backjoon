#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int Visit[101];
int blue_t[101];
int red_t[101];
int map[101][101];
int b_idx = -1;
int r_idx = -1;
int recur(int now, int team) {
	int i;
	Visit[now] = 1;
	if (!team) {
		blue_t[++b_idx] = now;
	}
	else {
		red_t[++r_idx] = now;
	}
	for (i = 1; i <= n; i++) {
		if (Visit[i] == 0 && map[now][i] == 0) {
			recur(i, !team);
		}
	}
	return 1;
}

int main() {
	int i, j;
	scanf_s("%d", &n);
	for (i = 0; i < 101; i++) {
		for (j = 0; j < 101; j++) map[i][j] = 1;
	}
	for (i = 1; i <= n; i++) {
		int m;
		scanf_s("%d", &m);
		for (j = 0; j < m; j++) {
			int a;
			scanf_s("%d", &a);
			map[i][a] = 0;
			map[a][i] = 0;
		}
	}
	for (i = 1; i <= n; i++) {
		if (Visit[i] == 0) {
			recur(i, 0);
		}
	}
	sort(blue_t, blue_t + 1 + b_idx);
	sort(red_t, red_t + 1 + r_idx);
	printf("%d\n", b_idx + 1);
	for (i = 0; i <= b_idx; i++) {
		printf("%d ", blue_t[i]);
	}
	printf("\n%d\n", r_idx + 1);
	for (i = 0; i <= r_idx; i++) {
		printf("%d ", red_t[i]);
	}
}