#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
int visit[1001];
int n;
void dfs(int p) {
	cout << p << " ";
	for (int i = 1; i <= n; i++) {
		if (visit[i] != 1 && map[p][i] == 1) {
			visit[i] = 1;
			dfs(i);
		}
	}
}
void bfs(int st) {
	queue<int> qu;
	qu.push(st);
	while (!qu.empty()) {
		int now = qu.front();
		cout << now << " ";
		for (int i = 1; i <= n; i++) {
			if (visit[i] != 1 && map[now][i] == 1) {
				qu.push(i);
				visit[i] = 1;
			}
		}
		qu.pop();
	}
}
int main()
{
	int m, v;
	cin >> n >> m >> v;
	visit[v] = 1;
	for (int i = 0; i < m; i++) {
		int st, fi;
		cin >> st >> fi;
		map[st][fi] = 1;
		map[fi][st] = 1;
	}
	dfs(v);
	cout << endl;
	for (int i = 0; i <= n; i++) {
		visit[i] = 0;
	}
	visit[v] = 1;
	bfs(v);
}