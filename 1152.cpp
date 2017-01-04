#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string str;
	int ans = 0;
	getline(cin, str);
	int size_ = str.length();
	cout << str << endl;
	for (int i = 0; i < size_; i++) {
		if (str[i] == ' ') ans++;	
	}
	if (str[0] == ' ') ans--;
	if (str[size_ - 1] == ' ') ans--;
	cout << ans+1<< endl;
}