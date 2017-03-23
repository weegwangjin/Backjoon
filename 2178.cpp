#include <iostream>
#include <string>
#include <queue>

using namespace std;

int map[101][101];
int visit[101][101];
int min_step = 999999999;

struct Node {
	int x;
	int y;
	int step;
};
queue<Node> qu;
int main()
{
	int n, m;
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		for (j = 1; j <= m; j++) {
			map[i][j] = tmp[j - 1] - '0';
		}
	}
	Node start = { 1,1,0 };
	qu.push(start);
	while (!qu.empty()) {
		visit[qu.front().x][qu.front().y] = 1;
		if (qu.front().x == n && qu.front().y == m) {
			if (min_step > qu.front().step) {
				min_step = qu.front().step;
				qu.pop();
				continue;
			}
			else {
				continue;
				qu.pop();
			}
		}
		int now_x = qu.front().x;
		int now_y = qu.front().y;
		//cout << now_x << " " << now_y << " "<<qu.front().step<<endl;
		Node next;
		if (now_x - 1 >= 1 && !visit[now_x - 1][now_y] && map[now_x-1][now_y] == 1) {
			next.x = now_x - 1;
			next.y = now_y;
			next.step = qu.front().step + 1;
			visit[next.x][next.y] = 1;
			qu.push(next);
		}
		if (now_x + 1 <= n && !visit[now_x + 1][now_y] && map[now_x + 1][now_y] == 1) {
			next.x = now_x + 1;
			next.y = now_y;
			next.step = qu.front().step + 1;
			visit[next.x][next.y] = 1;
			qu.push(next);
		}
		if (now_y +1 <= m && !visit[now_x][now_y+1] && map[now_x][now_y + 1] == 1) {
			next.x = now_x;
			next.y = now_y +1;
			next.step = qu.front().step + 1;
			visit[next.x][next.y] = 1;
			qu.push(next);
		}
		if (now_y -1 >=1 && !visit[now_x][now_y-1] && map[now_x][now_y-1] == 1) {
			next.x = now_x;
			next.y = now_y -1;
			next.step = qu.front().step + 1;
			visit[next.x][next.y] = 1;
			qu.push(next);
		}
		if(!qu.empty())
			qu.pop();
	}
	cout << min_step +1 << endl;

}