#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int num[1000];
	int ret[1000];
	int top = -1;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int *p = NULL;
	ret[++top] = num[0];
	for (int i = 1; i < n; i++) {
		if (ret[top] < num[i]) {
			ret[++top] = num[i];
			continue;
		}
		p = lower_bound(ret, ret + top, num[i]);
		*p = num[i];
	}
	cout << top+1 << endl;

}