#include <stdio.h>
#include <math.h>

int ma11in()
{
	int test_case;
	int a, b;
	int i;
	int count = 0;
	int c;
	int k;
	scanf_s("%d", &test_case);
	for (i = 0; i<test_case; i++) {
		long long cur_dis = 1;
		scanf_s("%lld %lld", &a, &b);
		c = b - a;
		k = (int) sqrt(c);
		count = 2 * (k - 1) + ((c - (k*k)) / k) + 1;
		printf("%d\n", k);
		}
		

	

	
}