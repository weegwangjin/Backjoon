#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int q = b % 10;
	int w = (b / 100);
	int e = (b - (b / 100) * 100) / 10;
	cout << a*q << endl << a*e << endl << a*w << endl << a*b << endl;
}