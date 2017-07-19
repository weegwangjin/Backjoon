#pragma warning(disable:4996)
#include<cstdio>
#include<queue>
#include<vector>
#include <iostream>

#define INF 0x7ffffff

using namespace std;
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
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int n, m, k, i, j, p;

		int r_min = 0;
		int r_index = 0;
		scanf("%d %d %d", &n, &m, &k);
		vector < pair < int, int > > * adj = new vector< pair < int, int > >[n];
		int **dist = new int*[k];
		for (i = 0; i < k; i++) {
			dist[i] = new int[n];
		}
		bool * visit = new bool[n];

		for (int i = 0; i < m; i++) {
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);
			adj[from - 1].push_back(make_pair(to - 1, cost));
			adj[to - 1].push_back(make_pair(from - 1, cost));
		}
		int *start = new int[k];
		for (i = 0; i < k; i++) {
			scanf("%d", &start[i]);
			r_index += start[i];
		}
		for (j = 0; j < k; j++) {
			for (int i = 0; i < n; i++) {
				dist[j][i] = INF;
				visit[i] = false;
			}
			dist[j][start[j] - 1] = 0;
			priority_queue < pair < int, int > > pq;
			pq.push(make_pair(-0, start[j] - 1));
			while (!pq.empty()) {
				int current_position = pq.top().second;
				pq.pop();
				if (visit[current_position] == true)
					continue;
				visit[current_position] = true;
				for (int i = 0; i < adj[current_position].size(); i++) {
					if (visit[adj[current_position].at(i).first] == false &&
						dist[j][adj[current_position].at(i).first] > dist[j][current_position] + adj[current_position].at(i).second) {
						dist[j][adj[current_position].at(i).first] = dist[j][current_position] + adj[current_position].at(i).second;
						pq.push(make_pair(-dist[j][adj[current_position].at(i).first], adj[current_position].at(i).first));
					}
				}
			}

		}

		for (i = 0; i < n; i++) {
			int min = 999999999;
			int index;
			int check = 0;
			for (j = 0; j < k; j++) {
				if (start[j] - 1 == i) {
					check = 1;
					break;
				}
			}

			if (check) continue;
			for (j = 0; j < k; j++) {
				if (dist[j][i] < min && dist[j][i] != 0) {
					min = dist[j][i];
					index = j + 1;
				}
			}
			r_min += min;
			r_index += index;
		}

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n%d\n", r_min, r_index);
		for (i = 0; i < k; i++) {
			delete[] dist[i];
		}
		delete[] dist;
		delete[] start;
		delete[] visit;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

