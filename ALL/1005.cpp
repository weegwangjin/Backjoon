#include <iostream>
#include <algorithm>

using namespace std;

int time_[1001];
int map[1001][1001];
int dp[1001];
int n;
int dfs(int p)
{
	if (dp[p] != 0) {
		return dp[p];
	}
	int ans = 0;
	int max_ = -1;
	int ck = 0;
	for (int i = 1; i <= n; i++) {
		if (map[i][p] == 1) {
			max_ = max(max_, time_[p]+ dfs(i));
			ck = 1;
		}
	}
	if (!ck) max_ = time_[p];
	dp[p] = max_;
	return dp[p];
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 1001; i++) {
			time_[i] = 0;
			dp[i] = 0;
		}
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				map[i][j] = 0;
			}
		}
		int k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> time_[i];
		}
		for (int i = 0; i < k; i++) {
			int st, fi;
			cin >> st >> fi;
			map[st][fi] = 1;
		}
		int w;
		cin >> w;
		int ans = dfs(w);
		cout << ans << endl;

	}
}