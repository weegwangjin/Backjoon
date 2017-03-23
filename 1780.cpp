#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int map[2188][2188];

int cnt[3];
void recur(int n,int st, int fi)
{
	int i, j;
	int ck = 0;
	int tmp = map[st][fi];
	for (i = st; !ck&& i < st + n; i++) {
		for (j = fi; !ck&&  j < fi + n; j++) {
			if (tmp != map[i][j]) {
				for (int p = st; p <= st + 2 * n / 3; p += n / 3) {
					for (int q = fi; q <= fi + 2 * n / 3; q += n / 3) {
						recur(n / 3, p, q);
					}
				}
				ck = 1;
			}
		}
	}
	if(!ck)cnt[tmp + 1]++;

	return;
}
int main()
{
	int n,i,j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int tmp = map[1][1];
	int ck = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (tmp != map[i][j]) {
				ck = 1;

			}
		}
	}
	recur(n, 1, 1);
	printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);

}