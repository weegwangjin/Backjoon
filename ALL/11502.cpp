#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int prime_[1001];
int s[1001][3];
int main()
{
	int t, i, j;
	int idx = 1;
	cin >> t;
	prime_[1] = 2; prime_[0] = 2;
	for (i = 3; i <= 1000; i++) {
		int ck = 1;
		for (j = 2; j*j <= i; j++) {
			if (!(i%j)) {
				ck = 0;
				break;
			}
		}
		if (ck) prime_[++idx] = i;
	}
	
	for (i = 1; i <= 1000; i++) {
		if (prime_[i]) {
			s[prime_[i]][0] = prime_[i - 1] - prime_[i];
			s[prime_[i]][2] = prime_[i + 1] - prime_[i];
		}
	}
	while (t--) {
		int k,p,q,r,j;
		cin >> k;
		vector<int> dp[1001][3];
		dp[7][0].push_back(2);
		dp[7][1].push_back(2);
		dp[7][2].push_back(3);
		for (i = 9; i <= k; i++) {
			vector<int> check[3];
			for (j = 0; j < dp[i - 2][0].size(); j++) {
				for (p = 0; p < 3; p++) {
					for (q = 0; q < 3; q++) {
						for (r = 0; r < 3; r++) {
							if (s[dp[i - 2][0].at(j)][p] + s[dp[i - 2][1].at(j)][q] + s[dp[i - 2][2].at(j)][r] == 2) {
								int ck = 1;
								int arr[3];
								arr[0] = s[dp[i - 2][0].at(j)][p] + dp[i - 2][0].at(j);
								arr[1] = s[dp[i - 2][1].at(j)][q] + dp[i - 2][1].at(j);
								arr[2] = s[dp[i - 2][2].at(j)][r] + dp[i - 2][2].at(j);
								sort(arr, arr + 3);
								for (int v = 0; v < check[0].size(); v++) {
									if (check[0].at(v) == arr[0] && check[1].at(v) == arr[1] && check[2].at(v) == arr[2]) {
										ck = 0;
										break;
									}
								}
								if (ck && dp[i][0].size()<=6) {
									check[0].push_back(arr[0]);
									check[1].push_back(arr[1]);
									check[2].push_back(arr[2]);
									dp[i][0].push_back(s[dp[i - 2][0].at(j)][p] + dp[i - 2][0].at(j));
									dp[i][1].push_back(s[dp[i - 2][1].at(j)][q] + dp[i - 2][1].at(j));
									dp[i][2].push_back(s[dp[i - 2][2].at(j)][r] + dp[i - 2][2].at(j));

								}

							}
						}
					}
				}
			}
		}
		cout << dp[k][0].at(0) << " " << dp[k][1].at(0) << " " << dp[k][2].at(0) << endl;
		
	}
}