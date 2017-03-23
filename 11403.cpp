#include <iostream>
#include <vector>
using namespace std;
int n;
int board[101][101];
int check[101][101];
int visit[101];

void dfs(int x, int y) {
	int i,k;
	int ck = 0;
	visit[y] = 1;
	for (i = 1; i <= n; i++) {
		if (board[y][i] == 1 && visit[i]==0) {
			dfs(y, i);
		}
		ck = 1;
	}
	if (!ck) return;
}
int main()
{

	int i, j,k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (board[i][j] == 1) {
				dfs(i, j);
			}
			for (k = 1; k <= n; k++) {
				
				if (check[i][k] == 1) {
					visit[k] = 0;
					continue;
				}
				check[i][k] = visit[k];
				visit[k] = 0;
			}
			
		}
	}
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << check[i][j]<<" ";
		}
		cout << endl;
	}
}

