#include <cstdio>
#include <cmath>
#include <stdlib.h>
int num[19];
int idx[11] = { 1,4,6,8,9,10,12,14,15,16,18 };
long double prob[11];
int combi(int n) {
	int a = 18;
	int b = n;
	long long sum = 1;
	long long sum1 = 1;
	for (int i = 1; i <= n; i++) {
		sum *= a--;
		sum1 *= b--;
	}
	return sum / sum1;
}

int main() {
	long double t_a, t_b;
	scanf_s("%lf %lf", &t_a, &t_b);
	t_a /= 100;
	t_b /= 100;
	for (int i = 0; i < 11; i++) {
		prob[i] = combi(idx[i])*pow(t_a, idx[i])*pow(t_b, abs(18 - idx[i]));
		printf("%d %0.10llf %0.10llf %0.10llf\n", combi(idx[i]), pow(t_a, idx[i]), pow(t_b, abs(18 - idx[i])),prob[i]);
	}
	long double ret = 0.0;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			ret += prob[i] * prob[j];
		}
	}
	printf("%0.10lf", 1-ret);
}