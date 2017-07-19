#include <iostream>

using namespace std;

int main()

{
	int num[7];
	for (int i = 1; i <= 6; i++) {
		cin >> num[i];
	}
	int ret = num[6];
	for (int i = 0; i < num[5]; i++) {
		num[1] -= 11;
		ret++;
	}
	for (int i = 0; i < num[4]; i++) {
		ret++;
		if (num[2] >= 5) {
			num[2] -= 5;
		}
		else {
			num[1] -= 4*(5 - num[2]);
			num[2] = 0;
			
		}
	}
	if(num[3]>=4)ret += num[3] / 4;
	num[3] %= 4;
	if (num[3] == 3) {
		if (num[2] >= 1) {
			num[2]--;
			num[1] -= 5;
		}
		else {
			num[1] -= 9;
		}
		ret++;
	}
	else if (num[3] == 2) {
		if (num[2] >= 3) {
			num[2] -= 3;
			num[1] -= 6;
		}
		else {
			num[1] -= 6 + 4 * (3 - num[2]);
			num[2] = 0;
		}
		ret++;
	}
	else if (num[3] == 1) {
		if (num[2] >= 4) {
			num[2] -= 4;
			num[1] -= 11;
		}
		else {
			num[1] -= 11 + 4*(4 - num[2]);
			num[2] = 0;
		}
		ret++;
	}
	if(num[2]>=9)ret += num[2] / 9;
	num[2] %= 9;
	if (num[2] >= 1) {
		num[1] -= 4 * (9 - num[2]);
		num[2] = 0;
		ret++;
	}
	if(num[1]>=36)ret += num[1] / 36;
	num[1] %= 36;
	if (num[1] >= 1) ret++;
	cout << ret << endl;

}