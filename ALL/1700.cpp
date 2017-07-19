#include <iostream>
#include <algorithm>

using namespace std;

int hole[101];
int util[101];
int order[101];
int idx = 1;
int main()
{
	int n, k, i, j;
	int ret = 0;
	cin >> n >> k;
	for (i = 1; i <= k; i++) {
		cin >> order[i];
		util[order[i]]++;
	}
	for (i = 1; i <= k; i++) {
		int ck = 0;
		if (idx <= n) {
			hole[idx++] = order[i];
			util[order[i]]--;
			if (!util[order[i]])
				util[order[i]] = -1;
			continue;
		}
		for (j = 1; j <= n; j++) {
			if (hole[j] == order[i])
				ck = 1;
		}
		if (ck) {
			continue;
		}
		int min_ = util[order[1]];
		int min_idx = order[1];
		for (j = 1; j <= n; j++) {
			if (min_ > util[hole[j]] && util[hole[j]] != 0) {
				min_ = util[hole[j]];
				min_idx = i;
			}
		}
		if (util[hole[min_idx]] == -1) {
			util[hole[min_idx]] = 0;
		}
		util[order[i]]--;
		if (util[order[i]] == 0)
			util[order[i]] = -1;
		hole[min_idx] = order[i];
		ret++;
	}
	cout << ret << endl;
	
}