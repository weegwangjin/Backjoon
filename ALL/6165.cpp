#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<long double> st;

int arr[200][2];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0]>>arr[i][1];
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			long double k = (arr[i][0] - arr[j][0] != 0) ? (arr[i][1] - arr[j][1]) / (long double)(arr[i][0] - arr[j][0]) : -9999999999;
			if (st.find(k) == st.end()) {
				st.insert(k);
			}
		}
	}
	cout << st.size() << endl;
}