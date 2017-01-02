#include <iostream>

using namespace std;

int dp[1000];
int arr[1000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0] = arr[0];
	int max_ = -1;
	for (int i = 1; i < n; i++) {
		int ck = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				if (max_ < dp[j]) {
					max_ = dp[j];
					ck = 1;
				}
			}
			else {
				dp[i] = arr[i];
			}
		}
		if (ck) dp[i] = arr[i] + max_;
		max_ = -1;
	}
	max_ = -1;
	for (int i = 0; i < n; i++) {
		if (dp[i] > max_) {
			max_ = dp[i];
		}
	}
	cout << max_ << endl;
}