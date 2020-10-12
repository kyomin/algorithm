#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int MAX_V = 20000;
const int INF = 1000000000; // 절대 나올 수 없는 경로값

typedef pair<int, int> P;

int main() {
	int V, E, K;

	// (이어진 정점 번호, 거리)
	vector<P> adj[MAX_V];

	scanf("%d %d %d", &V, &E, &K);

	K--;	// 인덱스를 맞추기 위함.

	// 인적리스트 정보 입력
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		adj[u - 1].push_back(P(v - 1, w));
	}

	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);

	bool visited[MAX_V] = { false, };

	// 최소 힙. first : dist[k], second : K(정점)
	priority_queue<P, vector<P>, greater<P>> PQ;
	dist[K] = 0;	// 시작점으로의 거리는 0
	PQ.push(P(0, K));	// 시작점만 PQ에 넣고 시작

	// PQ가 비면 종료
	while (!PQ.empty()) {
		int curr;

		curr = PQ.top().second;
		PQ.pop();

		visited[curr] = true;	// 방문

		for (auto &p : adj[curr]) {
			int next = p.first, d = p.second;

			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	// 결과 출력
	for (int i = 0; i < V; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}