#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


int dp[100001];
vector<int> vec;
int main()
{
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	vec.push_back(1);
	for (int i = 3; i <= n; i++) {
		for (int j = 2; j*j <= i; j++) {
			if (j*j == i) {
				dp[i] = 1;
				vec.push_back(i);
				break;
			}
		}
	}
	for (int i = 3; i <= n; i++) {
		if (dp[i] != 0) continue;
		int min_ = 999999999;
		for (int j = 0; j < vec.size(); j++) {
			if (vec[j] > i) break;
			min_ = min(min_, dp[vec[j]] + dp[i - vec[j]]);
		}
		dp[i] = min_;
	}
	cout << dp[n] << endl;
}