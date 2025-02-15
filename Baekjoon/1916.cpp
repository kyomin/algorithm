#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int MAX_V = 20000;
const int INF = 2000000000; // ���� ���� �� ���� ��ΰ�

typedef pair<int, int> P;

int main() {
	int N, M;
	int start, end;

	// (�̾��� ���� ��ȣ, �Ÿ�)
	vector<P> adj[MAX_V];

	scanf("%d %d", &N, &M);

	// ��������Ʈ ���� �Է�
	for (int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		adj[u - 1].push_back(P(v - 1, w));
	}

	scanf("%d %d", &start, &end);

	start--;
	end--;

	int dist[MAX_V];

	fill(dist, dist + MAX_V, INF);

	bool visited[MAX_V] = { false, };

	// �ּ� ��. first : dist[k], second : K(����)
	priority_queue<P, vector<P>, greater<P>> PQ;

	// ���ͽ�Ʈ�� �˰���
	dist[start] = 0;	// ������������ �Ÿ��� 0

	PQ.push(P(0, start));	// �������� PQ�� �ְ� ����

	// PQ�� ��� ����
	while (!PQ.empty()) {
		int curr;

		curr = PQ.top().second;
		PQ.pop();

		visited[curr] = true;	// �湮

		for (auto &p : adj[curr]) {
			int next = p.first, d = p.second;

			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	// ��� ���
	printf("%d\n", dist[end]);

	return 0;
}