#include <iostream>
#include <string>
using namespace std;

char ck[7] = { 'I','V','X','L','C','D','M' };
int val[300];

int make_(string str) {
	int ret = 0;
	int size_ = str.length();
	int now = -1;
	ret += val[str[0]];
	for (int i = 1; i < size_; i++) {
		if (val[str[i]]> val[str[i - 1]]) {
			ret -= val[str[i - 1]];
			ret += val[str[i]] - val[str[i - 1]];
			continue;
		}
		ret += val[str[i]];
	}
	return ret;
}

string make_1(int n) {
	string ret = "";
	for (int i = 0; i < n / 1000; i++) {
		ret += 'M';
	}
	n -= (n / 1000)*1000;
	if (n >= 900) {
		ret += "CM";
		n -= 900;
	}
	if (n >= 500) {
		n -= 500;
		ret += "D";
	}
	if (n >= 400) {
		ret += "CD";
		n -= 400;
	}
	while (n >= 100) {
		n -= 100;
		ret += "C";
	}
	if (n >= 90) {
		ret += "XC";
		n -= 90;
	}
	if (n >= 50) {
		n -= 50;
		ret += "L";
	}
	if (n >= 40) {
		ret += "XL";
		n -= 40;
	}
	while (n >= 10) {
		n -= 10;
		ret += "X";
	}
	if (n >= 9) {
		ret += "IX";
		n -= 9;
	}
	if (n >= 5) {
		n -= 5;
		ret += "V";
	}
	if (n >= 4) {
		ret += "IV";
		n -= 4;
	}
	while (n >= 1) {
		n -= 1;
		ret += "I";
	}
	return ret;
}
int main()
{

	val['I'] = 1;
	val['V'] = 5;
	val['X'] = 10;
	val['L'] = 50;
	val['C'] = 100;
	val['D'] = 500;
	val['M'] = 1000;
	string str1, str2;
	cin >> str1 >> str2 ;
	int ans = make_(str1) + make_(str2);
	cout<< ans<<endl<<make_1(3999);
	

}