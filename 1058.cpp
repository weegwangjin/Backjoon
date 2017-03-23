#include <iostream>
#include <string>

using namespace std;

string person[51];
int n;

int two_friends(int p) {
	int ret = 0;
	bool visit[50] = { 0, };
	for (int i = 0; i < n; i++) {
		if (person[p][i] == 'Y') {
			if (visit[i] == false) ret++;
			visit[i] = true;
			for (int j = 0; j < n; j++) {
				if (j != p && person[i][j] == 'Y' && visit[j] == false) {
					visit[j] = true;
					ret++;
				}
			}
		}
	}
	return ret;
}
int main()
{
	cin >> n;	
	for (int i = 0; i < n; i++) cin >> person[i];
	int max_ = -1;
	for (int i = 0; i < n; i++) {
		int k = two_friends(i);
		if (max_ < k) max_ = k;
	}
	cout << max_ << endl;
}