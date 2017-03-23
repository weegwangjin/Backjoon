#include <iostream>
#include <string>
#include <queue>

using namespace std;

string map[100];
int cnt = 999999999;
int n, m;
bool visit[100][100];

struct Node {
	int x;
	int y;
	int wall;
};
class Compare {
public:
	bool operator() (const Node& n1, const Node& n2) {
		return n1.wall > n2.wall;
	}
};
priority_queue<Node, vector<Node>, Compare> pq;
int main()
{
	int i, j;
	cin >> m >> n;
	for (i = 0; i < n; i++) {
		cin >> map[i];
	}
	Node start = { 0,0,0 };
	pq.push(start);
	visit[0][0] = 1;
	while (!(pq.top().x == n-1 && pq.top().y == m-1)) {
		int n_x = pq.top().x;
		int n_y = pq.top().y;
		int n_w = pq.top().wall;
		Node temp;
		if (n_x + 1 < n && !visit[n_x+1][n_y]) {
			temp.x = n_x + 1;
			temp.y = n_y;
			visit[n_x+1][n_y] = 1;
			if (map[n_x + 1][n_y] == '1') {
				temp.wall = n_w + 1;
			}
			else {
				temp.wall = n_w;
			}
			pq.push(temp);
		}
		if (n_x - 1 >= 0 && !visit[n_x - 1][n_y]) {
			temp.x = n_x - 1;
			temp.y = n_y;
			visit[n_x-1][n_y] = 1;
			if (map[n_x - 1][n_y] == '1') {
				temp.wall = n_w + 1;
			}
			else {
				temp.wall = n_w;
			}
			pq.push(temp);
		}
		if (n_y - 1 >= 0 && !visit[n_x][n_y-1]) {
			temp.x = n_x ;
			temp.y = n_y-1;
			visit[n_x][n_y-1] = 1;
			if (map[n_x ][n_y -1] == '1') {
				temp.wall = n_w + 1;
			}
			else {
				temp.wall = n_w;
			}
			pq.push(temp);
		}
		if (n_y + 1 < m && !visit[n_x][n_y+1]) {
			temp.x = n_x;
			temp.y = n_y+1;
			visit[n_x][n_y+1] = 1;
			if (map[n_x][n_y+1] == '1') {
				temp.wall = n_w + 1;
			}
			else {
				temp.wall = n_w;
			}
			pq.push(temp);
		}
		pq.pop();
	}
	cout << pq.top().wall << endl;
}