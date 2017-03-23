#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int map[402][402];

queue<int> pq;
int n, m;
int sum;
int bfs() {
	int i, j;
	int ret = 0;
	int parent[402];
	int visit[402];
	for (i = 0; i < 402; i++) {
		parent[i] = 0;
		visit[i] = 0;
	}
	pq.push(0);
	visit[0] = 1;
	while (!pq.empty()) {
		int now = pq.front();
		visit[now] = 1;
		if (now == 401) {
			ret = 1;
			while (!pq.empty()) {
				pq.pop();
			}
			break;
		}
		for (i = 0; i < 402; i++) {
			if (visit[i] == 0 && map[now][i] == 1) {
				parent[i] = now;
				pq.push(i);
			}
		}
		pq.pop();
	}
	if (ret) {
		int now = parent[401];
		int prev = 401;
		while (now != prev) {
			map[prev][now] = 0;
			map[now][prev] = 1;
			now = prev;
			prev = parent[prev];
		}
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 1; i <= n; i++) {
		map[0][i] = 1;
		int a;
		cin >> a;
		for (j = 0; j < a; j++) {
			int b;
			cin >> b;
			map[i][b+200] = 1;
		}
	}
	for (i = 201; i <= 200 + m; i++) {
		map[i][401] = 1;
	}
	int ck = 0;
	int sum = 0;
	do {
		ck = bfs();
		sum += ck;
	} while (ck);
		
	printf("%d\n", sum);
	
}