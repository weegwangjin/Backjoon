#include <iostream>

using namespace std;


int isopen[101];
int dp[101];

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			int p = 0;
			int m = 0;
			for (int j = i; j <= n; j += i) {
				isopen[j] = ~isopen[j];
				if (isopen[j]) p++;
				else m++;
			}
			dp[i] = dp[i - 1] + p - m;
		}

		cout << dp[n] << endl;
		for (int i = 0; i < 101; i++) {
			isopen[i] = 0;
			dp[i] = 0;
		}
	}
}