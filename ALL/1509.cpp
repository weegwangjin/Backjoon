#include <iostream>

using namespace std;

char str[2501];
int size_;

int ck(int left, int right)
{
	while(left <= right)
	{
		if (str[left] == str[right]) {
			left++;
			right--;
			continue;
		}
		return 0;
	}
	return 1;
}
int getdividecount(int idx) {
	int start = idx;
	int cnt = 0;
	int ret = 0;
	while (cnt + idx != size_) {
		for (int i = size_-1; i >=start; i--)
		{
			int check = ck(start, i);
			if (check) {
				cout << start<<" " << i << endl;
				cnt += i - start + 1;
				start = i+1;
				ret++;
				break;
			}
		}
		
	}
	return ret;
}
int main()
{
	cin >> str;
	size_ = strlen(str);
	cout << getdividecount(0) << endl;
}