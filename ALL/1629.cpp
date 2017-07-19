#include <cstdio>
#include <iostream>
using namespace std;

long long c;
long long mul(long long a, long long b) {
	if (b == 1) {
		return a%c;
	}
	long long tmp = mul(a, b / 2) % c;
	if (b % 2 == 0) {
		return ((tmp%c)*(tmp%c))%c;
	}
	else {
		return ((((a%c)*(tmp%c))%c)*(tmp%c))%c;
	}
}

int main() {
	long long a, b;
	cin >> a >> b >> c;
	long long ret = mul(a,b);
	cout << ret%c << endl;
}