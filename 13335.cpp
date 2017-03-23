#include <iostream>
#include <queue>
using namespace std;
int bridge[101];
int main()
{
	int n, w, L,i;

	int truck[1000];
	cin >> n >> w >> L;
	for (i = 0; i < n; i++) {
		cin >> truck[i];
	}
	int sum = 0;
	int idx = 0;
	int idx1 = -1;
	int ret = 0;
	int ck = 0;
	while (true) {
		for (i = 99; i >= 0; i--) {
			bridge[i + 1] = bridge[i];
		}
		bridge[0] = 0;
		sum -= bridge[w];
		if (sum + truck[idx] <= L && idx<n) {
			bridge[0] = truck[idx];
			sum += truck[idx];
			idx++;
			ret++;
		}
		else {
			ret++;

		}
		if (bridge[w] != 0) ck++;
		if (ck == n) break;
	
	}
	cout << ret << endl;
}