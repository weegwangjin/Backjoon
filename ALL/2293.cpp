#include <iostream>

using namespace std;

int coin[101];
int cnt[10001][2];
int main()
{
	int n, k,i,j;
	cin >> n >> k;
	for (i = 1; i <= n;i++) {
		cin >> coin[i];
	}
	for (i = 1; i <= k; i++) {
		if (i % coin[1] == 0) {
			cnt[i][0]++;
		}
	}
	for (j = 2; j <= n; j++) {
		for (i = 1; i <= k; i++) {
			if (i / coin[j] > 0) {
				for (int p = 1; p <= i / coin[j]; p++) {
					int tmp = i- coin[j]*p;
					cnt[i][1] += cnt[tmp][0];
					if (tmp == 0) cnt[i][1]++;
				}
				cnt[i][1] += cnt[i][0];
			}
			else {
				cnt[i][1] = cnt[i][0];
			}
		}
		for (i = 1; i <= k; i++) {
			cnt[i][0] = cnt[i][1];
			cnt[i][1] = 0;
		}
	}
	cout << cnt[k][0] << endl;


}