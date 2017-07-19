#include <iostream>

using namespace std;

int map[101][101];
int n;
long long ans;
int dfs(int x, int y) {
	if (x == n && y == n) {
		ans++;
		return 0;
	}
	if (x + map[x][y] <= n) dfs(x + map[x][y], y);
	if (y + map[x][y] <= n) dfs(x, y + map[x][y]);

	return 0;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	dfs(1, 1);

	cout << ans << endl;
}