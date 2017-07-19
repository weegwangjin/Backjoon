#include <iostream>
#include <algorithm>

using namespace std;
int n;
int train[50001];
int dp[50001][3];
int T;
int sum[50001];
int main()
{
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> train[i];
		sum[i] += train[i] + sum[i - 1];
	}
	cin >> T;
	for (i = 1; i <= n - (3 * T - 1); i++) {
		dp[i][0] = max(dp[i - 1][0], sum[i+T-1]-sum[i-1]);
	}
	for (j = T+1; j <= n - (2 * T - 1); j++) {
		dp[j][1] = max(dp[j - 1][1], sum[j+T-1]-sum[j-1]+ dp[j-T][0]);
	}
	for (k = 2*T+1; k <= n - (T - 1); k++) {
		dp[k][2] = max(dp[k - 1][2], sum[k+T-1]-sum[k-1]+dp[k-T][1]);
	}
	cout << dp[k - 1][2] << endl;
}