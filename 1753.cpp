#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include<vector>

using namespace std;

priority_queue<pair<int, int> > pq;
vector<pair<int, int> > *nodes;

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		nodes = NULL;
		while (!pq.empty()) {
			pq.pop();
		}
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int v, e, k, f;
		int i, j, p;
		cin >> v >> e >> k;
		nodes = new vector<pair<int, int> >[v];
		for (i = 0; i < e; i++) {
			int u, v1, w;
			cin >> u >> v1 >> w;
			nodes[u - 1].push_back(make_pair(v1 - 1, w));
			nodes[v1 - 1].push_back(make_pair(u - 1, w));
		}
		
		int r_min = 0;
		int r_min_index = 0;

		int *shelter = new int[k];
		for (i = 0; i < k; i++) {
			cin >> shelter[i];
			shelter[i]--;
			r_min_index += shelter[i] + 1;
		}
		int **dist = new int*[k];
		for (i = 0; i < k; i++) {
			dist[i] = new int[v];
		}
		for (p = 0; p <k; p++) {

			int start = shelter[p];
			
			bool *check = new bool[v];
			for (i = 0; i < v; i++) {
				check[i] = false;
				dist[p][i] = 999999999;
				if (i == start)
					dist[p][i] = 0;
			}
			pq.push(make_pair(-0, start));
			while (!pq.empty()) {
				int top_first, top_second;
				int check1 = 0;
				top_first = -pq.top().first;
				top_second = pq.top().second;
				pq.pop();
				if (check[top_second])
					continue;
				check[top_second] = true;
				for (i = 0; i < nodes[top_second].size(); i++) {
					int fromAtoNode, fromAtoIdxtoNode;
					fromAtoNode = dist[p][nodes[top_second].at(i).first];
					fromAtoIdxtoNode = top_first + nodes[top_second].at(i).second;
					if (fromAtoNode > fromAtoIdxtoNode) {
						dist[p][nodes[top_second].at(i).first] = fromAtoIdxtoNode;
						pq.push(make_pair(-fromAtoIdxtoNode, nodes[top_second].at(i).first));
					}
				}

			}
			
			delete[] check;
		}
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		for (i = 0; i < v; i++) {
			int min = 999999999;
			int min_index;
			int check = 0;
			for (p = 0; p < k; p++) {
				if (shelter[p] == i) {
					check = 1;
					break;
				}
			}
			if (check) continue;

			for (j = 0; j < k; j++) {
				if (min > dist[j][i] && dist[j][i] != 0) {
					min = dist[j][i];
					min_index = j+1;
				}
			}
			r_min += min;
			r_min_index += min_index;
		}
		printf("Case #%d\n", test_case);
		printf("%d\n%d\n", r_min, r_min_index);

		delete[] nodes;
		delete[] shelter;
		delete[] dist;

		
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}