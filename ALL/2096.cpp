#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001][3];
int dp[2][3];

int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	dp[1][0] = dp[0][0] = arr[1][0];
	dp[1][1] = dp[0][1] = arr[1][1];
	dp[1][2] = dp[0][2] = arr[1][2];
	
	for (int i = 2; i <= n; i++) {
		int a, b, c, d, e, f;
		a = min(dp[0][0], dp[0][1]) + arr[i][0];
		b = min(dp[0][1], min(dp[0][0], dp[0][2]))+ arr[i][1];
		c = min(dp[0][1], dp[0][2]) + arr[i][2];
		d = max(dp[1][0], dp[1][1]) + arr[i][0];
		e = max(dp[1][1], max(dp[1][0], dp[1][2]))+ arr[i][1];
		f = max(dp[1][1], dp[1][2]) + arr[i][2];
		dp[0][0] = a;
		dp[0][1] = b;
		dp[0][2] = c;
		dp[1][0] = d;
		dp[1][1] = e;
		dp[1][2] = f;
	}
	cout << max(dp[1][0],max(dp[1][1],dp[1][2])) << " " << min(dp[0][0],min(dp[0][1],dp[0][2])) << endl;
}