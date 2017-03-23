#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

int num[10];
int idx;
int main()
{
	string n;
	cin >> n;
	int size_ = n.length();
	for (int i = 0; i < size_; i++) {
		num[idx++] = n[i] - '0';
	}
	sort(num, num + idx, greater<int>());
	for (int i = 0; i < size_; i++) {
		cout << num[i];
	}
}