#include <iostream>
#include <cmath>

using namespace std;

int num[100];
bool prime_[1000001];
int prime[78498];
int prime2[78498];
int prime1[100][78498];
int gcd[78498];
int idx = -1;
long long result = 1;
void divid(int n,int idx_)
{
	int i;
	while (n >=2) {
		for (i = 0; i < 78498; i++) {
			if (n < 2) break;
			while (n%prime[i] == 0) {
				n /= prime[i];
				prime1[idx_][i]++;
				prime2[i]++;
			}
		}
	}
}
void find(int n)
{
	int i, j;
	for (i = 2; i <= n; i += 2) prime_[i] = 1;
	for (i = 3; i*i <= n; i += 2)
	{
		if (prime_[i] == 0) {
			for (j = i*i; j <= n; j+=i) {
				prime_[j] = 1;
			}
		}
	}
	prime_[0] = 1;
	prime_[1] = 1;
	prime_[2] = 0;
}
int main() {
	int n,i,j;
	cin >> n;
	find(1000000);
	for (i = 2; i <= 1000000; i++) {


		if (prime_[i] == 0) {
			prime[++idx] = i;
		}
	}
	for (i = 0; i < n; i++) {
		cin >> num[i];
		divid(num[i],i);
	}
	for (i = 0; i < 78498; i++) {
		result *= pow(prime[i],(prime2[i] / n));
		gcd[i] = prime2[i] / n;
	}
	int result1 = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 78498; j++) {
			if (gcd[j] != 0) {
				if (prime1[i][j] -gcd[j] < 0) {
					result1 += -(prime1[i][j]- gcd[j]);
				}
			}
		}
	}
	cout<<result<< " "<<result1<<endl;
	

}