#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int idx[1000001];
int arr[500001];
int main()
{
	set<pair<int, int>> st;
	int n;
	cin >> n;


	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		idx[k] = i;
	}
	for (int i = 1; i <= n; i++) arr[i] = idx[arr[i]];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j<i && arr[j]> arr[i]) {
				if (st.find({ i,j }) == st.end()) {
					st.insert(make_pair(i, j));
					st.insert(make_pair(j, i));
				}
			}
			if (j > i && arr[j] < arr[i]) {
				if (st.find({ i,j }) == st.end()) {
					st.insert(make_pair(i, j));
					st.insert(make_pair(j, i));
				}
			}
		}
	}
	cout << st.size() / 2 << endl;
}