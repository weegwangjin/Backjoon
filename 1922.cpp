#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

#define MaxSize 100010

int N, M, set[MaxSize], sum;

struct Node

{

	int x, y, w;

}cost[MaxSize];

bool compare(const Node &i, const Node &j) { return i.w<j.w; }

int f(int i)

{

	if (set[i] == i) return i;

	return set[i] = f(set[i]);

}

int main()

{
	int i, ra, rb;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++)

	{
		scanf("%d %d %d", &cost[i].x, &cost[i].y, &cost[i].w);
	}
	sort(cost + 1, cost + 1 + M, compare);
	for (i = 1; i <= N; i++) set[i] = i;
	for (i = 1; i <= M; i++)

	{

		ra = f(cost[i].x);

		rb = f(cost[i].y);

		if (ra == rb) continue;

		ra>rb ? set[ra] = rb : set[rb] = ra;

		sum += cost[i].w;

	}

	printf("%d", sum);

	return 0;

}
