#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> vec(100001);
int main()
{
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.begin() + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		if (binary_search(vec.begin(), vec.begin()+n, k)) cout << "1" << endl;
		else cout << "0" << endl;
	}
}