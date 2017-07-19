#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%0.10f", (double)a / (double)b);
}