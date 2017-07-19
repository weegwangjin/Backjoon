#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main()
{
	string a;
	string b;
	int i, j;
	cin >> a >> b;
	int max_idx;
	if (a.length() < b.length()) {
		string tmp = b;
		b = a;
		a = tmp;
	}
	max_idx = a.length();
	for (i = 1; i <= max_idx; i++) {
		for (j = 1; j <= max_idx; j++) {
			if (j <= a.length() - b.length()) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			else {
				if (a[i - 1] == b[j - 1-a.length()+b.length()]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
	}
	cout << dp[max_idx][max_idx] << endl;

}