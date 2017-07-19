#include <iostream>
#include <algorithm>

using namespace std;

int map[101][101];
int visit[101];
int n,a, b, m;
int min_ = 999999999;
void dfs(int st, int fi, int now, int step) {
	visit[now] = 1;
	if (now == fi) {
		min_ = min(min_, step);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (map[now][i] == 1 && visit[i] == 0) {
			dfs(st, fi, i, step + 1);
		}
	}
	visit[now] = 0;
	
}
int main()
{

	cin >> n >> a >> b>>m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	dfs(a, b, a, 0);

	if (min_ == 999999999) cout << "-1" << endl;
	else cout << min_ << endl;
}