#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int len_[1000];
int dp[1000][2];
int dfs(int idx, int sum)
{
	
	if (dp[idx - 1][0] - 1 >= len_[idx]) {

	}
}

int main()
{

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> len_[i];
	}

	dp[0][0] = len_[0];
	dp[0][1] = 0xFFFFFFFF-1;

}