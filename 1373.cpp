#include <iostream>
#include <string>

using namespace std;

int st[340000];
int top = -1;
int main()
{
	string str;
	cin >> str;
	int size_ = str.length();
	int p = 1;
	int sum = 0;
	for (int i = size_ - 1; i >= 0; i--) {
		sum += (str[i] - '0') * p;
		p *= 2;
		if (p == 8 || i==0) {
			p = 1;
			st[++top] = sum;
			sum = 0;
		}
	}
	for (int i = top; i >= 0; i--) {
		cout << st[i];
	}
}