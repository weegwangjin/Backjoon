#include <iostream>
#include <vector>
using namespace std;

pair<int, int> vec[50];
int cnt[50];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cnt[i] = 1;
		vec[i].first = a;
		vec[i].second = b;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second) cnt[i]++;
		}
	}
	for (int i = 0; i < n; i++) cout << cnt[i] << endl;
}