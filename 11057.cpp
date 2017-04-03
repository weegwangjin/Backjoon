#include <iostream>

using namespace std;

long long dp[1001][10];
int main()
{
	int n;
	cin >> n;
	dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = dp[1][7] = dp[1][8] = dp[1][9] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][k] += dp[i - 1][j] % 10007;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += (dp[n][i] % 10007);
		sum = sum % 10007;
	}
	cout << sum %10007 << endl;
}