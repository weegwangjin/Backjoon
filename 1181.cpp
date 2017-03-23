#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string str[20000];
int n;
bool compare(const string &a, const string &b) {
	int a_s = a.length();
	int b_s = b.length();
	if (a_s == b_s) {
		return a < b;
	}
	else {
		return a_s < b_s;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str + n, compare);
	cout << str[0] << endl;
	for (int i = 1; i < n; i++) {
		if (str[i] == str[i - 1]) continue;
		cout << str[i] << endl;
	}
}