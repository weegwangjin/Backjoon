#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);
	long long ans = (long long)ceil((sqrt(n)));
	printf("%lld", ans);


}