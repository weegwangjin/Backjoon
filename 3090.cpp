#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100001];
int n;
int T;
int max_ = 999999999;
struct Node {
	int sub;
	int prev;
	int next;
};

class compare {
public:
	bool operator() (const Node& n1, const Node& n2) {
		return n1.sub < n2.sub;
	}
};
priority_queue<Node, vector<Node>, compare> pq;
int main()
{
	int i, j;
	cin >> n >> T;
	cin >> arr[1];
	int now = arr[1];
	for (i = 2; i <= n; i++) {
		cin >> arr[i];
		Node node = { abs(now - arr[i]),i - 1,i };
		pq.push(node);
		now = arr[i];
	}
	for (i = 1; i <= T; i++) {
		while (true) {
			if (abs(arr[pq.top().prev] - arr[pq.top().next]) != pq.top().sub) {
				int sub = abs(arr[pq.top().prev] - arr[pq.top().next]);
				Node node = { sub,pq.top().prev,pq.top().next };
				pq.pop();
				pq.push(node);
			}
			else {
				break;
			}
		}
		if (pq.top().sub > max_-1) {
			break;
		}
		if (arr[pq.top().prev] > pq.top().next) {
			arr[pq.top().prev]--;
		}
		else {
			arr[pq.top().next]--;
		}
		Node node = { pq.top().sub - 1, pq.top().prev ,pq.top().next };
		max_ = pq.top().sub;
		pq.pop();
		pq.push(node);
	}
	for (i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}