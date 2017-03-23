#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int hanoi(int n, int a, int b, int c)
{
	if (n == 1) {
		printf("%d %d\n", a, c);
		return 0;
	}
	hanoi(n - 1, a, c, b);
	printf("%d %d\n", a, c);
	hanoi(n - 1, b, a, c);
}
int main()
{
	int n,size_;
	scanf("%d", &n);
	size_ = pow(2, n) - 1;
	printf("%d\n", size_);
	hanoi(n, 1, 2, 3);
}