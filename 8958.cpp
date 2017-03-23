#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int size_ = str.length();
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < size_; i++) {
			if (str[i] == 'X') cnt = 0;
			if (str[i] == 'O') {
				cnt++;
				sum += cnt;
			}
		}
		cout << sum << endl;
	}
}