#include <stdio.h>


int mai1111n()
{
	int test_case;
	long long a, b;
	int i;
	long long c;
	long long dis[3] = { 0,1,2 };
	int check;
	
	scanf_s("%d", &test_case);
	for (i = 0; i<test_case; i++) {
		long long cur_dis = 1;
		scanf_s("%lld %lld", &a, &b);
		c = b - a- 1;
		int count = 2;
		
		for (; ; ) {
			printf("%d -> ", cur_dis);
			
			if (cur_dis == c) {
				break;
			}
			
			else {
				if (((((dis[2]) + 1)*(dis[2]) / 2) + cur_dis  <= c) || ((((dis[2]) + 1)*(dis[2]) / 2) + cur_dis -1<= c)) {
					cur_dis += dis[2];
					dis[0] = dis[2] - 1;
					dis[1] = dis[2];
					dis[2] = dis[2] + 1;
				}


				else if (((((dis[1]) + 1)*(dis[1]) / 2) + cur_dis <= c) || ((((dis[1]) + 1)*(dis[1]) / 2) + cur_dis -1 <= c)) {
					cur_dis += dis[1];
				}
				else if (((((dis[0]) + 1)*(dis[0]) / 2) + cur_dis <= c) || ((((dis[0]) + 1)*(dis[0]) / 2) + cur_dis - 1 <= c)) {
					cur_dis += dis[0];

					dis[1] = dis[0];
					dis[2] = dis[0] + 1;
					dis[0] = dis[0] - 1;
				}
				count++;
				printf("%d \n ", cur_dis);
			}
		}
		printf("\n%d\n", count);



	}
}