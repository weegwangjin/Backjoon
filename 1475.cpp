#include <iostream>
#include <string>
using namespace std;

int num[10];

int main()
{
	string n;
	cin >> n;
	int size_ = n.length();
	for (int i = 0; i < size_; i++) {
		num[n[i] - '0']++;
	}
	num[6] += num[9];
	if (num[6] % 2 == 1) num[6]++;
	num[6] /= 2;
	int max_ = -1;
	for (int i = 0; i < 9; i++) {
		if (max_ < num[i]) max_ = num[i];
	}
	cout << max_ << endl;
}