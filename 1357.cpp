#include <iostream>
#include <cmath>

using namespace std;
int p;
int sum(int n, int step)
{
	if (n / 10 == 0) {
		p = step;
		return (n%10)*pow(10, p-step);
	}
	return sum(n / 10, step + 1) + (n%10)*pow(10, p-step);
}
int rev(int k)
{
	int ret = sum(k, 0);	
	return ret;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << rev(rev(a) + rev(b)) << endl;
}