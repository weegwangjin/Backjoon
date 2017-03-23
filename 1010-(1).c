#include <stdio.h>

int main_b()
{
	int matrix[31][31];
	
	int i, j, k;
	int test_case, a, b;
	int temp;
	int result;
	scanf_s("%d", &test_case);

	for (k = 0; k < test_case; k++) {
		matrix[0][0] = 1;
		matrix[0][1] = 1;
		matrix[1][0] = 1;
		scanf_s("%d %d", &a, &b);

		temp = b - a;
		if (a == b) {
			result = 1;
			
		}
		else {
			for (i = 0; i <= a; i++) {
				for (j = 0; j <= temp; j++) {
					if (i - 1 < 0 && j - 1 >= 0) matrix[i][j] = matrix[i][j - 1];
					else if (i - 1 >= 0 && j - 1 < 0) matrix[i][j] = matrix[i - 1][j];
					else if (i == 0 && j == 0) continue;
					else matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];

				}
			}
			result = matrix[a][temp];
		}
		
		printf("%d\n", result);
	}
}