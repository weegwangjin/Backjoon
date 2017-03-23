#include <iostream>
#include <algorithm>
using namespace std;
long long s[100001];
long long dp[100001];
long long max_;
int main() {
	int n,i;
	cin >> n;
	for (i = 0; i < n;i++) {
		cin >> s[i];
	}
	dp[0] = s[0];
	max_ = dp[0];
	for (i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + s[i], s[i]);
		max_ = max(max_, dp[i]);
	}
	cout << max_ << endl;
}