#include <stdio.h>
#include <stdlib.h>

int dicision(int x1, int y1, int r1, int x2, int y2, int r2) {
	if ((x1 == x2) && (y1 == y2) && (r1 == r2)) return -1;
	else if ((((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) > (r1 + r2) *(r1 + r2)) || (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < (r1 - r2) *(r1 - r2))) return 0;
	else if ((x1 == x2) && (y1 == y2) && (r1 != r2)) return 0;
	else if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) == (r1 + r2) *(r1 + r2)) return 1;
	else if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) == (r1 - r2) *(r1 - r2)) return 1;
	else if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < (r1 + r2) *(r1 + r2)) return 2;
	
}

int main35()
{
	int test_case;
	int i;
	
	scanf_s("%d", &test_case);
	for (i = 0; i < test_case; i++) {
		int x1, y1, r1, x2, y2, r2;

		scanf_s("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		printf("%d\n", dicision(x1, y1, r1, x2, y2, r2));
	}
}