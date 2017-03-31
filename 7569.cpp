#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int map[101][101][101];
int visit[101][101][101];
int m, n, h;
struct node {
	int x, y, z,step;
};
int step_;
queue<node> qu;

void bfs() {
	
	while (!qu.empty()) {
		int n_x = qu.front().x;
		int n_y = qu.front().y;
		int n_z = qu.front().z;
		int n_step = qu.front().step;
		qu.pop();
		step_ = n_step;
		if (n_x - 1 >= 1 && map[n_x-1][n_y][n_z] == 0 && visit[n_x-1][n_y][n_z] == 0) {
			qu.push({ n_x-1,n_y,n_z,n_step + 1 });
			visit[n_x - 1][n_y][n_z] = 1;
			map[n_x-1][n_y][n_z] = 1;
		}
		if (n_x + 1 <= n && map[n_x+1][n_y][n_z] == 0 && visit[n_x+1][n_y][n_z] == 0) {
			qu.push({ n_x+1,n_y,n_z,n_step + 1 });
			visit[n_x + 1][n_y][n_z] = 1;
			map[n_x+1][n_y][n_z] = 1;
		}
		if (n_y -1 >= 1 && map[n_x][n_y-1][n_z] == 0 && visit[n_x][n_y-1][n_z] == 0) {
			qu.push({ n_x,n_y-1,n_z,n_step + 1 });
			visit[n_x][n_y-1][n_z] = 1;
			map[n_x][n_y-1][n_z] = 1;
		}
		if (n_y +1 <=m && map[n_x][n_y+1][n_z] == 0 && visit[n_x][n_y+1][n_z] == 0) {
			qu.push({ n_x,n_y+1,n_z,n_step + 1 });
			visit[n_x][n_y+1][n_z] = 1;
			map[n_x][n_y+1][n_z] = 1;
		}
		if (n_z -1 >=1 && map[n_x][n_y][n_z-1] == 0 && visit[n_x][n_y][n_z-1] == 0) {
			qu.push({ n_x,n_y,n_z-1,n_step + 1 });
			visit[n_x][n_y][n_z-1] = 1;
			map[n_x][n_y][n_z-1] = 1;
		}
		if (n_z +1 <= h && map[n_x][n_y][n_z+1] == 0 && visit[n_x][n_y][n_z+1] == 0) {
			qu.push({ n_x,n_y,n_z+1,n_step + 1 });
			visit[n_x][n_y][n_z+1] = 1;
			map[n_x][n_y][n_z+1] = 1;
		}
	}
}
int main()
{

	cin >> m >> n >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				cin >> map[j][k][i];
				if (map[j][k][i] == 1) {
					qu.push({ j,k,i,0 });
					visit[j][k][i] = 1;
				}

			}
		}
	}
	bfs();
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (map[j][k][i] == 0) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	cout << step_ << endl;
}