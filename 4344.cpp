#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[1000];
		double sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		sum = sum/(double) n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (sum < arr[i]) {
				cnt++;
			}
		}
		printf("%0.3f%%\n", (double)cnt/(double)n * 100);
	
	}
}