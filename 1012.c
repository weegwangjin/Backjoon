#include <stdio.h>
#include <stdlib.h>
typedef struct loctype
{
	int x;
	int y;
	int z;
} loc;

int decision(loc x1, loc x2) {
	if ((x2.z ==0)&&((x2.x == x1.x) && (x2.y == (x1.y) - 1 || x2.y == x1.y + 1)) )return 1;
	else if ((x2.z == 0)&&((x2.y == x1.y) && (x2.x == (x1.x) - 1 || x2.x == x1.x + 1))) return 1;
	else return 0;
}

int main()
{
	int t;
	scanf_s("%d", &t);
	while (t--) {
		int height, width,number;
		int i;
		int result = 0;
		scanf_s("%d %d %d", &height, &width,&number);
		loc *a = (loc*)malloc(sizeof(loc)*number);
		for (i = 0; i < number; i++) {
			a[i].x = -1;
			a[i].y = -1;
			a[i].z = 0;
		}
		for (i = 0; i < number; i++) {
			scanf_s("%d %d", &a[i].x, &a[i].y);
		}
	
		
		while (1) {
			int check = 0;
			loc *b = (loc*)malloc(sizeof(loc)*number);
			for (i = 0; i < number; i++) {
				b[i].x = -1;
				b[i].y = -1;
				b[i].z = 0;
			}
			for (i = 0; i < number; i++) {
				if (a[i].z == 0) {
					check = 1;
					b[0].x = a[i].x; b[0].y = a[i].y; a[i].z = 1;
					break;
				}
			}
			if (check == 0) break;
			int index = 0;
			int k = 0;
			while (b[k].x != -1) {
				for (i = 0; i < number; i++) {
					if (decision(b[k], a[i])) {
						index++;
						b[index].x = a[i].x;
						b[index].y = a[i].y;
						a[i].z = 1;
					}
				}
				k++;
				if (k == number) break;
			}
			
			
			result++;
			
		}
		printf("%d\n", result);
	}
	return 0;
}