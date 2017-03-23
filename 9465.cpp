#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int i, j,n;
		int stk[2][100002];
		int sub[2][100002];
		scanf("%d", &n);
		for (i = 0; i < 2; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &stk[i][j]);
			}
		}
		for (i = 0; i < 2; i++) {
			int sum = 0;
			for (j = 0; j < n; j++) {
				if (i - 1 >= 0) {
					sum += stk[i - 1][j];
				}
				if (!i) {
					sum += stk[i + 1][j];
				}
				if (j - 1 >= 0) {
					sum += stk[i][j - 1];
				}
				if (j + 1 < n) {
					sum += stk[i][j + 1];
				}
				sub[i][j] = stk[i][j] - sum;
			}
		}
		int sum = 0;
		for (i = 0; i < 2; i++) {
			int max_ = -1;
			for (j = 0; j < n; j++) {
				if (i) {
					max_ = max(sub[i][j], sub[i - 1][j]);
				}
				if (!i) {
					max_ = max(sub[i][j], sub[i + 1][j]);
				}
				if (j - 1 >= 0) {
					max_ = max(sub[i][j], sub[i][j - 1]);
				}
				if (j + 1 < n) {
					max_ = max(sub[i][j], sub[i][j + 1]);
				}
				if (max_ == sub[i][j]) {

				}
			}
		}
	}
}