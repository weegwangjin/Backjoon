#include <iostream>
#include <algorithm>

using namespace std;

int n;
int wine[10001];
struct Node {
	int no;
	int pprev;
	int prev;
};
Node node[10001];
int max_ = -1;
int main()
{
	int i;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	node[1].pprev = wine[1];
	node[1].prev = wine[1];
	max_ = wine[1];
	for (i = 2; i <= n; i++) {
		node[i].no = max_;	
		node[i].pprev = wine[i] + max(node[i - 2].pprev, node[i - 2].prev);
		node[i].pprev = max(node[i].pprev, node[i - 1].no + wine[i]);
		node[i].prev = wine[i] + node[i - 1].pprev;
		if (max_ < node[i].pprev)
			max_ = node[i].pprev;
		if (max_ < node[i].prev)
			max_ = node[i].prev;
	}
	cout << max_ << endl;
}