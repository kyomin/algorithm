#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int MAX_V = 20000;
const int INF = 1000000000; // ���� ���� �� ���� ��ΰ�

typedef pair<int, int> P;

int main() {
	int V, E, K;

	// (�̾��� ���� ��ȣ, �Ÿ�)
	vector<P> adj[MAX_V];

	scanf("%d %d %d", &V, &E, &K);

	K--;	// �ε����� ���߱� ����.

	// ��������Ʈ ���� �Է�
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		adj[u - 1].push_back(P(v - 1, w));
	}

	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);

	bool visited[MAX_V] = { false, };

	// �ּ� ��. first : dist[k], second : K(����)
	priority_queue<P, vector<P>, greater<P>> PQ;
	dist[K] = 0;	// ������������ �Ÿ��� 0
	PQ.push(P(0, K));	// �������� PQ�� �ְ� ����

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
	for (int i = 0; i < V; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}