#include <iostream>

using namespace std;

char str[1001];

int ck(int left, int right)
{
	while (left < right) {
		if (str[left] == str[right]) {
			left++;
			right--;
			continue;
		}
		return 0;
	}
	return 1;
}
int main()
{

	cin >> str;
	int ret = strlen(str);
	for (int i = 0; i < ret; i++) {
		if (ck(i, ret - 1)) {
			cout << ret + i << endl;
			return 0;
		}
	}
}