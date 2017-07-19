#include <stdio.h>
#include <math.h>

char c_black[8][8] = { 'B','W','B','W', 'B','W', 'B','W', 'W', 'B','W', 'B','W', 'B','W', 'B', 'B','W', 'B','W', 'B','W', 'B','W', 'W', 'B','W', 'B','W', 'B','W', 'B', 'B','W', 'B','W', 'B','W', 'B','W','W', 'B','W', 'B','W', 'B','W', 'B', 'B','W', 'B','W', 'B','W', 'B','W', 'W','B','W','B','W','B','W','B'};
char c_white[8][8] = { 'W','B','W', 'B','W', 'B','W','B', 'B','W', 'B','W', 'B','W', 'B','W','W', 'B','W', 'B','W', 'B','W', 'B', 'B', 'W', 'B','W', 'B','W', 'B','W', 'W', 'B','W', 'B','W', 'B','W','B','B','W', 'B','W', 'B','W', 'B','W','W', 'B', 'W', 'B','W', 'B','W', 'B','B','W', 'B','W','B','W','B','W' };
int c_min[50][50];
char board[50][51];
int main()
{
	int m, n,i,j;
	scanf_s("%d %d", &m, &n);
	getchar();
	for (i = 0; i < m; i++) {
		fgets(&board[i][0],sizeof(board),stdin);
	}
	for (i = 0; i < m - 7; i++) {
		for (j = 0; j < n - 7; j++) {
			int num = 0; int num1 = 0;
			for (int k = 0; k < 8; k++) {
				for (int p = 0; p < 8; p++) {
					if (c_black[k][p] == board[i + k][j + p]) num++;
					if (c_white[k][p] == board[i + k][j + p]) num1++;
				}
			}
			c_min[i][j] = (num >= num1) ? num : num1;
		}
	}
	int max = c_min[0][0];
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			if (max < c_min[i][j]) 	max = c_min[i][j];
		}
	}
	printf("%d", 64-max);
}