#include <iostream>
#include <vector>
using namespace std;


vector<int> arr;
int visit[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	int now = 0;
	visit[0] = 1;
	cout << 1 << " ";
	int t = n-1;
	while (t--) {
		int k = arr[now];
		for (int i = 0; i < abs(k); i++) {
			if (k < 0) {
				now--;
				if (now < 0) now += n;
				if (visit[now] == 1) {
					i--;
					continue;
				}

			}
			else {
				now++;
				if (now >= n) now -= n;
				if (visit[now] == 1) {
					i--;
					continue;
				}
				
			}
			
		}
		cout << now+1 << " ";
		visit[now] = 1;
	}
}