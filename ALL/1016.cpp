#include <stdio.h>
#include <math.h>
long long prime_n[78498];
int main()
{
	long long i,j;
	long long a, b;
	int index = 0;
	
	scanf_s("%lld %lld", &a, &b);
	long long count = 0;
	index = 0;
	for (i = 2; i <= sqrt(b); i++) {
		int cnt1 = 0;
		for (j = 2; j <= sqrt(i); j++) {
			if (i%j == 0) {
				cnt1 = 1;
				break;
			}
		}
		if (cnt1 == 0) {
			prime_n[index] = i*i; index++;
		}
	}
	//for (i = 0; i < 78498; i++) {
	//	printf("%lld \n", prime_n[i]);
	//}
	int check = 0;
	for (i = 0; prime_n[i]!=0 && prime_n[i] <= b; i++) {
		if (a % prime_n[i] == 0) {
			if (check == 1) count--;
			count += 1 + (b / prime_n[i])
				a- (a / prime_n[i]);
			//printf("%lld %lld \n", prime_n[i], count);
			check = 1;
		}
		else if(((a / prime_n[i]) + 1)*prime_n[i] <=b) {
			count += 1 + (b / prime_n[i]) - ((a / prime_n[i]) + 1);
			
		}
	}
	printf("%lld", (b-a+1)-count);
	
}