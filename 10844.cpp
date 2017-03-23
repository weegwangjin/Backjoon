#include <iostream>

using namespace std;


long long dp[101][10];
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 9 << endl;
		return 0;
	}
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[2][2] = 2;
	dp[2][3] = 2;
	dp[2][4] = 2;
	dp[2][5] = 2;
	dp[2][6] = 2;
	dp[2][7] = 2;
	dp[2][8] = 2;
	dp[2][9] = 1;
	for (int i = 3; i <= n; i++) {
		for (int j = 0; j < 10; j++) 
		{
			long long tmp = 0;
			if (j - 1 >= 0) {
				tmp += dp[i - 1][j - 1];
			}
			if (j + 1 < 10) {
				tmp += dp[i - 1][j + 1];
			}
			dp[i][j] += tmp % 1000000000;
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
		ans %= 1000000000;
	}
	cout << ans%1000000000 << endl;
}