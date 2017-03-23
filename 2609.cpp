#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (b==0) {
		return a;
	}
	return gcd(b, a%b);
	
}

int main()
{
	int x, y;
	cin >> x >> y;
	int result = gcd(max(x, y), min(x, y));
	cout << result << endl << x*y/result << endl;
}