#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
	int n;
	cin >> n;
	char str[100][11];
	cin >> str[0];
	for (int i = 1; i < n; i++) cin >> str[i];
	for (int i = 0; i < n; i++) sort(str[i], str[i] + 10);
}