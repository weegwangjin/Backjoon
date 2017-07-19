#include <iostream>
#include <algorithm>

using namespace std;


int dp[1001];
int price[1001];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> price[i];
	dp[1] = price[1];

	for (int i = 2; i <= n; i++) {
		int max_ = price[i];
		for (int j = i - 1; j>=i-j; j--) {
			max_ = max(max_, dp[j] + dp[i - j]);
		}
		dp[i] = max_;
	}
	cout << dp[n] << endl;
}