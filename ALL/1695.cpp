#include <cstdio>
#include <algorithm>
using namespace std;

int arr[5001];
int r_arr[5001];

int lcs[5001][5001];
int main() {
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &arr[i]);
		r_arr[n - i + 1] = arr[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (r_arr[i] == arr[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	printf("%d", n-lcs[n][n]);
}