#include <iostream>

using namespace std;

int val[101];
int dp[10001];
int main()
{
	int n, k;
	cin >> n >> k;
	int i,j;
	for (i = 1; i <= n; i++) {
		cin >> val[i];
		dp[val[i]] = 1;
	}
	for (i = 1; i <= k; i++) {
		if (dp[i] != 0) continue;
		int min_ = 999999999;
		for (j = 1; j <= i / 2; j++) {
			if (i % 2 == 0) {
				if (j == i / 2) {
					if (min_ > dp[j] * 2)
						min_ = dp[j] * 2;
				}
				else {
					if (min_ > dp[j] + dp[i - j])
						min_ = dp[j] + dp[i - j];
				}
			}
			else {
				if (min_ > dp[j] + dp[i - j])
					min_ = dp[j] + dp[i - j];
			}
		}
		dp[i] = min_;
	}
	if (dp[k] == 999999999)
		dp[k] = -1;
	cout << dp[k] << endl;
}