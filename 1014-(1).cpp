#include <stdio.h>

int main()
{
	int t;
	scanf_s("%d", &t);
	while (t--) {
		int n,m;
		char seat;
		scanf_s("%d %d", &n, &m);
		int o_c = 0;
		int e_c = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf_s(" %c", &seat);
				if (j % 2 == 0 && seat == '.') {
					e_c++;
				}
				else if(j % 2 == 1 && seat == '.') {
				    o_c++;
				}
			}
		}
		int ret;
		ret = (e_c > o_c) ? e_c : o_c;
		printf("%d\n", ret);


	}
}