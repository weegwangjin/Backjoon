#include <iostream>
#include <algorithm>

using namespace std;

class Data {
public:
	int a, b;
};
bool compare(const Data &i, const Data &j) {
	return i.a<j.a;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		Data arr[100001];
		int n,i,j;
		cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> arr[i].a >> arr[i].b;
		}
		int ret = 1;
		sort(arr+1, arr + n+1, compare);
		int min_ = arr[1].b;
		for (i = 2; i <= n; i++) {
			if (arr[i].b < min_) {
				min_ = arr[i].b;
				ret++;
			}
		}
		cout << ret << endl;
	}
}