#include <iostream>
#include <queue>

using namespace std;

queue<long long>qu;
int main()
{
	int n;
	cin >> n;
	if (n < 10) {
		cout << n << endl;
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		qu.push(i);
	}
	long long now = qu.front();
	int ck = 0;
	int cnt = 0;
	while (!qu.empty()) {
		now = qu.front();
		cout << cnt << " " << now << endl;
		int one = now % 10;
		for (int i = 0; i < one; i++) {
			qu.push(now * 10 +
				
				i);
		}
		qu.pop();
		if (cnt == n) {
			ck = 1;
			break;
		}
		cnt++;
	}
	if (!ck) now = -1;
	cout << now << endl;
}