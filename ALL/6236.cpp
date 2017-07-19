#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int arr[100001];
int n, m;
int sum[100001];
int max_ = -1;
struct Node {
	int x, y;
	int val;
};
priority_queue<Node> pq;
void divide(int st, int fi)
{
	Node left;
	Node right;
	for (int i = st; i <= fi; i++) {
		if (sum[i]-sum[st-1] >= sum[fi] - sum[i]) {
			if (max(sum[i]-sum[st-1], sum[fi] - sum[i]) > max(sum[i - 1]-sum[st-1], sum[fi] - sum[i - 1])) {
				
				left.x = st;
				left.y = i - 1;
				left.val = sum[i - 1] - sum[st - 1];
				right.x = i;
				right.y = fi;
				right.val = sum[fi] - sum[i - 1];
				pq.push(left);
				pq.push(right);
				return;
			}
			else {
				left.x = st;
				left.y = i;
				left.val = sum[i] - sum[st - 1];
				right.x = i + 1;
				right.y = fi;
				right.val = sum[fi] - sum[i];
				pq.push(left);
				pq.push(right);
				return;
			}
		}
	}
}


bool operator <(const Node &a, const Node &b)
{
	return a.val < b.val;
}
int main()
{
	int i;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}

	Node now = { 1,n,sum[n] - sum[0] };
	pq.push(now);
	int ck = 0;
	while (pq.size() != m) {
		if (pq.top().x == pq.top().y) {
			if (max_ < pq.top().val) {
				max_ = pq.top().val;
				ck = 1;
				Node tmp = pq.top();
				tmp.val = -tmp.val;
				pq.pop();
				pq.push(tmp);
			}
		}
		divide(pq.top().x, pq.top().y);
		pq.pop();		
	}
	if (ck) printf("%d\n", max_);
	else { printf("%d\n", pq.top().val); }

}
