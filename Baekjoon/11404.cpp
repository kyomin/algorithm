#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int MAX_V = 20000;
const int INF = 2000000000; // 절대 나올 수 없는 경로값

typedef pair<int, int> P;

vector<P> adj[MAX_V];		// (이어진 정점 번호, 거리)
vector<int> result[MAX_V];

int n, m;
int dist[MAX_V];
bool visited[MAX_V];

// 최소 힙. first : dist[k], second : K(정점)
priority_queue<P, vector<P>, greater<P>> PQ;

// 다익스트라 알고리즘
void solution(int start) {
	fill(dist, dist + MAX_V, INF);
	fill(visited, visited + MAX_V, false);

	dist[start] = 0;	// 시작점으로의 거리는 0
	PQ.push(P(0, start));	// 시작점만 PQ에 넣고 시작

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

	// 결과 담기
	for (int i = 0; i < n; i++) {
		if (dist[i] == INF)
			result[start].push_back(0);
		else
			result[start].push_back(dist[i]);
	}
}

int main() {
	scanf("%d %d", &n, &m);

	// 인접 리스트 정보 입력
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		adj[u - 1].push_back(P(v - 1, w));
	}

	for (int i = 0; i < n; i++)
		solution(i);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", result[i][j]);

		printf("\n");
	}

	return 0;
}