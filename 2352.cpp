#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> vec1;

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	vec1.push_back(vec[0]);
	for (i = 1; i < vec.size(); i++) {
		if (vec1.back() < vec[i]) {
			vec1.push_back(vec[i]);
		}
		else {
			vector<int>::iterator it = lower_bound(vec1.begin(), vec1.end(), vec[i]);
			*it = vec[i];
		}
	}
	cout << vec1.size() << endl;
}