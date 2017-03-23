#include <stdio.h>
#include <stdlib.h>


int dic1ision(int x, int y,int x1, int y1, int r1)
{
	if ((x - x1)*(x - x1) + (y - y1) *(y - y1) <= r1*r1) return 1;
	else return 0;
}


int m1ain()
{
	int test_case;
	int i,j;
	
	int planet;
	int x1, y1, x2, y2;
	scanf_s("%d", &test_case);
	for (i = 0; i < test_case; i++) {
		int result = 0;
		scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf_s("%d", &planet);
		int cx;
		int cy;
		int r;
		for (j = 0; j < planet; j++) {
			scanf_s("%d %d %d", &cx, &cy, &r);
			if (dicision(x1, y1, cx, cy, r) && dicision(x2, y2, cx, cy, r)) continue;
			result += dicision(x1, y1, cx, cy, r);
			result += dicision(x2, y2, cx, cy, r);
		}
		printf("%d\n", result);
	}
}