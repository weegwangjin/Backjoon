#include <iostream>
#include <string>
using namespace std;

int cnt[26];

int main()
{
	string str;
	cin >> str;
	int size_ = str.length();
	for (int i = 0; i < size_; i++) {
		if (str[i] > 90) cnt[str[i] - 'a']++;
		else cnt[str[i] - 'A']++;
	}
	int max_ = -1;
	char max_1;
	int ck = 0;
	for (int i = 0; i < 26; i++) {
		if (max_ == cnt[i]) {
			ck = 1;
		}
		if (max_ < cnt[i]) {
			max_ = cnt[i];
			max_1 = 'A' + i;
			ck = 0;
		}
	}
	if(!ck)cout << max_1 << endl;
	else cout << "?" << endl;

}