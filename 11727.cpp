#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long dp[1000];
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i < n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2)%10007;
	}
	cout << dp[n - 1]%10007 << endl;
}