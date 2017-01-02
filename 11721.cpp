#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int size_ = str.length();
	for (int i = 1; i <= size_; i++) {
		if (i % 10 == 0) cout << endl;
		cout << str[i-1];
	}
}