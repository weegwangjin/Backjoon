#include <cstdio>
bool ck[10001];
int main() {
	int now = 1;
	while (now != 10001) {
		if (!ck[now])
			printf("%d\n", now);
		int tmp = now;
		int k = 10000;
		int sum = tmp;
		while (k>0) {
			sum += tmp / k;
			tmp -= (tmp / k)*k;
			k /= 10;
		}
		if (sum <= 10000)
			ck[sum] = true;
		now++;
	}
}