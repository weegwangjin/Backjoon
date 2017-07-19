#include <stdio.h>


int func(int n, int m)
{
	if (n == 0 && m >= 1)
		return 1;
	else if (m == 0)
		return 1;
	else
		return func(n - 1, m) + func(n, m - 1);
}

int main_ab()
{
	int test_case, i;
	int a, b;
	int n, m;
	int result;
	scanf_s("%d", &test_case);
	for (i = 0; i < test_case; i++) {
		scanf_s("%d %d", &a, &b);
		n = a;
		m = b -a;

		if (a == b)
			result = 1;
		else {
			result = func(n, m);
		}

		printf("%d\n", result);
	}
}