#include <iostream>

using namespace std;

int map[101][101];
int min_ = 999999999;
int visit[101];
int n;
int m_map[101];
int r_min = 999999999;
int sum;
int r_index = -1;
int level_[101];
int dfs(int x, int y,int level,int target) {
	int i, j;
	int ck = 0;
	visit[y] = 1;
	level_[level] = y;
	if (y == target) {
		if (min_ > level) {
			
			min_ = level;
		}
		visit[y] = 0;
		return level;
	}

	for (i = 1; i <= n; i++) {
		if (visit[i] == 0 && map[y][i] == 1) {
			ck = 1;
			dfs(y, i, level + 1, target);
			ck = 0;
		}
	}
	if (!ck) {
		visit[y] = 0;
		return 999999999;
	}
}

int main()
{
	int m;
	cin >> n >> m;
	int i, j;
	for (i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		map[from][to] = 1;
		map[to][from] = 1;
	}
	for (i = 1; i <= n; i++) {
		for (int p = 1; p <= n; p++) {
			int ck = 0;
			for (j = 1; j <= n; j++) {
				int tmp;
				if (map[i][j] == 1 && i != p) {
					visit[i] = 1;
					tmp = dfs(i, j, 1, p);
					ck = 1;
					if (min_ > tmp)
						min_ = tmp;
					for (int q = 1; q <= n; q++) {
						visit[q] = 0;
					}
				}
			}
			if (ck) {
				sum += min_;
				min_ = 999999999;
			}
		}
		if (r_min > sum) {
			r_min = sum;
			r_index = i;
		}

		sum = 0;
		
	}

	cout << r_index << endl;
}