#include <stdio.h>

int main()
{
	int t;
	scanf_s("%d", &t);
	while (t--) {
		int room[12][12];
		int ret = 0;
		int i, j,n,m;
		scanf_s("%d %d", &n, &m);
		char seat;
		int count[12][12];
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				scanf_s(" %c", &seat);
				if (seat == '.') {
					room[i][j] = 1;
					count[i][j] = 0;
				}
				else if (seat == 'x') {
					count[i][j] = 1000; room[i][j] = 0;
				}
			}
		}
		for (i = 0; i <= n+1; i++) {
			for (j = 0; j <= m+1; j++) {
				if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
					room[i][j] = 0;
					count[i][j] = 1000;
				}
			}
		}
		while(1){
			int check = 0;
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= m; j++) {
					if (room[i][j] == 0) continue;
					else {
						check = 1;
						if (room[i - 1][j - 1] == 1) count[i][j]++;
						if (room[i - 1][j + 1] == 1) count[i][j]++;
						if (room[i][j - 1] == 1) count[i][j]++;
						if (room[i][j + 1] == 1) count[i][j]++;
						if (room[i + 1][j + 1] == 1) count[i][j]++;
						if (room[i + 1][j - 1] == 1) count[i][j]++;
					}
				}
			}
			if (check == 0) break;
			int min = count[1][1];
			int min_x=1;
			int min_y= 1;
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= m; j++) {
					if (min > count[i][j]) {
						min = count[i][j];
						min_x = i;
						min_y = j;
					}
				}
			}
				room[min_x][min_y] = 0;room[min_x - 1][min_y - 1] = 0;room[min_x - 1][min_y + 1] = 0;room[min_x][min_y - 1] = 0;room[min_x][min_y + 1] = 0;room[min_x + 1][min_y - 1] = 0;room[min_x + 1][min_y + 1] = 0;count[min_x][min_y] = 1000;count[min_x - 1][min_y - 1] = 1000;count[min_x - 1][min_y + 1] = 1000;count[min_x][min_y - 1] = 1000;count[min_x][min_y + 1] = 1000;count[min_x + 1][min_y - 1] = 1000;count[min_x + 1][min_y + 1] = 1000;
				ret++;
				for (i = 1; i <= n; i++) {
					for (j = 1; j <= m; j++) {
						if (room[i][j] == 1) count[i][j] = 0;
					}
				}
		}
		printf("%d\n", ret);
	}
	return 0;
}