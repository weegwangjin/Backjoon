#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int dp[1001];
int arr[1001];
vector<int> lis;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	/*for (int i = 2; i <= n; i++) {
		for (int j = 1; j <=i-1; j++) {
			if (arr[i] > arr[j] && dp[i]< dp[j]+1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int answer = -1;
	for (int i = 1; i <= n; i++) answer = max(answer, dp[i]);
	cout << answer << endl; */
	lis.push_back(arr[1]);
	for (int i = 2; i <= n; i++) {
		if (arr[i] > lis[lis.size() - 1]) {
			lis.push_back(arr[i]);
		}
		else {
			vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), arr[i]);
			*it = arr[i];
		}
	}
	cout << lis.size() << endl;


}