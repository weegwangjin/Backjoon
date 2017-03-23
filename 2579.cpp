#include <iostream>

using namespace std;

typedef struct nodetype {
	int pprev;
	int prev;
}Node;
Node node[301];
int score[301];
int r_score[301];
int n;

int main()
{
	int i;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin>>score[i];
	}
	node[1].pprev = score[1];
	r_score[1] = score[1];
	node[2].pprev = score[2];
	node[2].prev = score[1] + score[2];
	r_score[2] = (node[2].pprev > node[2].prev) ? node[2].pprev : node[2].prev;
	for (i = 3; i <= n; i++) {
		node[i].pprev = (node[i - 2].pprev > node[i - 2].prev) ? node[i - 2].pprev : node[i - 2].prev;
		node[i].pprev += score[i];
		node[i].prev = node[i - 1].pprev + score[i];
		r_score[i] = (node[i].pprev > node[i].prev) ? node[i].pprev : node[i].prev;
	}
	cout << r_score[n] << endl;
	


}