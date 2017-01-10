#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int A[50];
	int B[50];
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	sort(A, A + n);
	for (int i = 0; i < n; i++) {
		int max_ = -1;
		int max_idx = 0;
		for (int j = 0; j < n; j++) {
			if (B[j] != -1 && max_ < B[j]) {
				max_ = B[j];
				max_idx = j;
			}
		}
		B[max_idx] = -1;
		ans += A[i] * max_;
	}
	cout << ans << endl;
}