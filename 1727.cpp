#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int man[1001];
int woman[1001];
int dp[1001][1001];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i =1; i <= n; i++) {
		cin >> man[i];

	}
	for (int i = 1; i <= m; i++) {
		cin >> woman[i];
	}
	sort(man+1, man+1 + n);
	sort(woman+1, woman +1+ m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j) {
				dp[i][j] = dp[i - 1][j - 1] + abs(man[i] - woman[j]);
			}
			if (i > j) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(man[i] - woman[j]));
			}
			if (i < j) {
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(man[i] - woman[j]));
			}
		}
	}
	cout << dp[n][m] << endl;
}