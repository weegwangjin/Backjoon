#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include<vector>

using namespace std;

priority_queue<pair<int, int> > pq;
vector<pair<int, int> > *nodes;

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
		nodes = NULL;
		while (!pq.empty()) {
			pq.pop();
		}
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
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

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}