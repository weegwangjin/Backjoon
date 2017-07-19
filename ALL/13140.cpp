#include <cstdio>
#include <algorithm>

using namespace std;
int P;
bool visit[10];
int num[7] = { 1,1000,10000,120,1001,100,10000 };
int num_[7];
int perm(int step, int sum)
{
	//wprintf("%d %d \n", step, sum);
	int i;
	if (step == 7) {
		//printf("%d %d\n", sum==P,P);
		return sum == P;
	}
	for (i = 0; i < 10; i++)
	{
		if (visit[i] == 1) continue;	
		if ((step == 2 || step == 6) && i == 0) {
			continue;
		}
		if (visit[i] == 0) {
			visit[i] = 1;
			num_[step] = i;
			int ck = perm(step + 1, sum + num[step] * i);
			//if (step == 6) printf(" adsfads %d\n", ck);
			if (ck==1) {
				//printf("erewyiu");
				return true;
			}
			visit[i] = 0;			
		}
	}
}

int main() {

	scanf_s("%d", &P);
	if (perm(0, 0)==1) {
		printf("  %d%d%d%d%d\n",num_[2],num_[1],num_[3],num_[3],num_[4]);
		printf("+ %d%d%d%d%d\n", num_[6], num_[4], num_[5], num_[3], num_[0]);
		printf("-------\n");
		printf("%7d\n", num[0]*num_[0]+num[1]*num_[1]+num[2]*num_[2] + num[3]*num_[3]+ num[4]*num_[4]+num[5]*num_[5] + num[6]*num_[6]);
	}
	else {
		printf("No Answer");
	}
	return 0;

}


