#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string str[50];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	int size_ = str[0].length();
	for (int i = 0; i < size_; i++) {
		int ck = 0;
		for (int j = 1; j < n; j++) {
			if (str[j][i] != str[j - 1][i]) {
				ck = 1;
				break;
			}
		}
		if(!ck) cout << str[0][i];
		else cout << "?";
	}
}