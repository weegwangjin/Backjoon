#pragma warning(disable:4996)
#include<cstdio>
#include<queue>
#include<vector>
#include <iostream>

#define INF 0x7ffffff

using namespace std;
int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n%d\n", r_min, r_index);
		for (i = 0; i < k; i++) {
			delete[] dist[i];
		}
		delete[] dist;
		delete[] start;
		delete[] visit;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}

