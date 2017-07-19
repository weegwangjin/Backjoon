#include <cstdio>
#include <algorithm>

using namespace std;
int card[1000];
int dp[1000][1000][2];

int recur(int st, int fi, bool Alice) {
	if (st > fi) return 0;
	int &ret = dp[st][fi][Alice];
	if (ret != 0) {
		return ret;
	}
	if (Alice) {
		return ret = max(card[st] + recur(st + 1, fi, false), card[fi] + recur(st, fi - 1, false));
	}
	else {
		return ret = min(recur(st + 1, fi, true), recur(st, fi - 1, true));
	}
	
}
int main() {
	int t;
	scanf_s("%d", &t);
	while (t--) {
		int n,i,j;
		scanf_s("%d", &n);
		for (i = 0; i < n; i++) {
			scanf_s("%d", &card[i]);
		}
		int st = 0;
		int fi = n - 1;
		printf("%d\n", recur(st, fi, true));
		for (i = 0; i < 1000; i++) {
			for (j = 0; j < 1000; j++) {
				dp[i][j][0] = 0;
				dp[i][j][1] = 0;
			}
		}
		
	}
}