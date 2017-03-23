#include <stdio.h>


int main_1()
{
	int test_case;
	int i;
	int a, b;
	int temp;
	int result;
	scanf_s("%d", &test_case);
	for (i = 0; i<test_case; i++) {
		scanf_s("%d %d", &a, &b);
		temp = a % 10;
		switch (temp) {
		case 1:
			result = 1;
			break;
		case 2:
			b = b % 4 ;
			if (b == 0) result = 6;
			else if(b == 1) result = 2;
			else if (b == 2) result = 4;
			else result = 8;

			break;
		case 3:
			b %= 4;
			if (b == 0) result = 1;
			else if (b == 1) result = 3;
			else if (b == 2) result = 9;
			else result = 7;
			break;
		case 4:
			b = b % 2;
			if (b == 0) result = 6;
			else result = 4;
			break;
		case 5:
			result = 5;
			break;
		case 6:
			result = 6;
			break;
		case 7 :
			b %= 4;
			if (b == 0) result = 1;
			else if (b == 1) result = 7;
			else if (b == 2) result = 9;
			else result = 3;
			break;
		case 8 :
			b %= 4;
			if (b == 0) result = 6;
			else if (b == 1) result = 8;
			else if (b == 2) result = 4;
			else result = 2;
			break;
		case 9 :
			b = b % 2;
			if (b == 0) result = 1;
			else result = 9;
			break;
		case 0 :
			result = 10;
			break;

			}
		printf("%d\n", result);
		}
	return 1;
	}
