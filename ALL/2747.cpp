#include <iostream>

using namespace std;
unsigned long long dp[10001],i,n;

int main()
{
	dp[0] = 0;
	dp[1] = 1;
	cin >> n;
	for (i = 2; i <= 10000; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n];
}