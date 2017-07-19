#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> vec[32001];
int edge[32001];

int main()
{
	int i, j;
	cin >> n >> m;
	while(m--) {
		int a, b;
		cin >> a >> b;
		edge[b]++;
		vec[a].push_back(b);
	}
	int ck = 1;
	while (ck==1) {
		for (i = 1; i <= n; i++) {
			if (edge[i] == 0) {
				for (j = 0; j < vec[i].size(); j++) {
					edge[vec[i].at(j)]--;
				}
				edge[i] = -1;
				cout << i << " ";
				ck = 2;
			}
		}
		if (ck == 2) {
			ck = 1;
		}
		else {
			ck = 0;
		}
	}
}