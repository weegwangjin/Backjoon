#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);
	int size_ = -1;
	for (int i = 63; i >= 0; i--) {
		long long tmp = n;
		tmp = tmp >> i;
		if (1 & tmp) {
			size_ = i;
			break;
		}
	}
	if (size_ % 2 == 1) size_--;
	for (long long i = 2 >> (size_ / 2); i <= n; i++) {
		if (i*i >= n) {
			printf("%lld", i);
			return 0;
		}
	}


}