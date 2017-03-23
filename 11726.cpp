#include <iostream>
using namespace std;
long long d[1001];
int main() {
	int n,i;
	cin >> n;
	d[0] = d[1]=1;
	for (i = 2; i <= n; i++)
		d[i] = (d[i - 1] + d[i - 2])%10007;
	cout << d[n] << endl;
}