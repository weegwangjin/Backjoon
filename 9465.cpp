#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;


int dp[2][100001];
int arr[2][100001];


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0;i<2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			dp[0][i] = max(dp[0][i - 1], arr[0][i] + dp[1][i - 1]);
			dp[1][i] = max(dp[1][i - 1], arr[1][i] + dp[0][i - 1]);
		}
		cout << max(dp[0][n], dp[1][n]) << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = 0;
			}
		}
	}
	
}