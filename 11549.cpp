#include <cstdio>

int main()
{
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < 5; i++) {
		int a;
		scanf("%d", &a);
		if (a == n) cnt++;
	}
	printf("%d", cnt);
}