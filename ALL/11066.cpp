#include <cstdio>
int sum[501];
int dp[501][501];
int main() {
	int t;
	scanf_s("%d", &t);
	while (t--) {
		int k,i;
		int num[501];
		scanf_s("%d", &k);
		for (i = 0; i < k; i++) {
			scanf_s("%d", &num[i]);
		}
		sum[0] = 0;
		for (i = 1; i <= k; i++) {
			sum[i] = num[i - 1] + sum[i - 1];
		}
		sum[0] = 0;
		int j = 0;
		for (i = 0; i < k; i++) {
			for (j = i; j >= 0; j--) {
				if (i == j) {
					dp[i][j] = 0;
					continue;
				}
				if (i-j == 1) {
					dp[i][j] = num[i] + num[j];
					continue;
				}
				int x_1 = j;
				int y_1 = j;
				int x_2 = j + 1;
				int y_2 = i;
				int min_ = 999999999;
				while (y_1<i) {
					if (min_ > dp[y_1][x_1]+ dp[y_2][x_2]) {
						min_ = dp[y_1][x_1] + dp[y_2][x_2];
					}
					y_1++;
					x_2++;
					
				}
				dp[i][j] = min_+sum[i+1] - sum[j];
			}
		}
		printf("%d\n", dp[k-1][0]);
		for (i = 0; i < 501; i++) sum[i] = 0;
		for (i = 0; i < 501; i++) {
			for (j = 0; j < 501; j++) {
				dp[i][j] = 0;
			}
		}
	}
}