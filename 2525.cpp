#include <iostream>

using namespace std;

int main()
{
	int h, m, k;
	cin >> h >> m >> k;
	cout << (h + (m + k) / 60) % 24 << " " << (m + k) % 60 << endl;
}