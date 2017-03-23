#include <iostream>

using namespace std;

int val[501][501];
int dp[501][501];

int main()
{
	int n,i,j;
	cin >> n;
	int sum = (n*(n + 1) )/ 2;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			cin >> val[i][j];
		}
	}
	dp[1][1] = val[1][1];
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			if (j - 1 <= 0) {
				dp[i][j] = dp[i - 1][j] + val[i][j];
			}
			else if (j > i) {
				dp[i][j] = dp[i - 1][j - 1] + val[i][j];
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] > dp[i - 1][j]) ? dp[i - 1][j - 1] : dp[i - 1][j];
				dp[i][j] += val[i][j];
			}
		}
	}
	int max = dp[n][1];
	for (i = 2; i <= n; i++) {
		if (max < dp[n][i]) max = dp[n][i];
	}
	cout << max << endl;
}