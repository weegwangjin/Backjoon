#include <iostream>

using namespace std;
int n,k,i,j;
int arr[50001];
int sum[50001];
struct Node {
	int one;
	int two;
	int three;
};
Node dp[50001];
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> k;
	for (i = 1; i <= n - k + 1; i++) {
		for (j = i; j < i + k; j++) {
			sum[i] += arr[j];
		}
	}
	dp[1].one = sum[1];
	for (i = 2; i < n; i++) {
		dp[i].one = sum[i];
		int max_1 = -1;
		int max_2 = -1;
		for (j = 1; j <= i - k; j++) {
			if (max_1 < dp[j].one) {
				max_1 = dp[j].one;
			}
			if (dp[j].two != 0) {
				if (max_2 < dp[j].two) {
					max_2 = dp[j].two;
				}
			}
		}
		if (max_1 != -1) {
			dp[i].two = dp[i].one + max_1;
		}
		if (max_2 != -1) {
			dp[i].three = dp[i].one + max_2;
		}
	}
	int max_ = dp[1].three;
	for (i = 2; i < n; i++) {
		if (max_ < dp[i].three) {
			max_ = dp[i].three;
		}
	}
	cout << max_ << endl;
}