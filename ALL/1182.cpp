#include <iostream>
#include <algorithm>
using namespace std;
int num[20];
int cnt = 0;
int visit[20];
int s,n;
int recur(int k, int step,int sum, int now)
{
	if (k == step) {
		visit[now] = 0;
		if (sum == s) {
			cnt++;
		}
		return 0;
	}
	for (int i = now+1; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			recur(k, step + 1, sum + num[i],i);
		}
	}
	visit[now] = 0;
}
int main()
{
	int i;
	cin >> n >> s;

	for (i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	for (i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			recur(i, 1, num[j], j);
		}
	}
	cout << cnt << endl;

}