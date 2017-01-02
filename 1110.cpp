#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>


int main()
{
	int n;
	scanf("%d", &n);
	int st = n/10;
	int fi = n % 10;
	int cnt = 0;
	int a = st;
	int b = fi;
	while (true) {
		int tmp = a;
		a = b;
		b = (tmp+a)%10 ;
		cnt++;
		if (a == st && b == fi) break;
	}
	printf("%d", cnt);
	return 0;
}