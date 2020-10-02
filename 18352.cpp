#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, X;

int dist[300001];		// X 노드로부터 각 노드와의 최단거리
bool check[300001];
vector<int> a[300001];	// 인접리스트

void bfs(int node) {
	queue<int> q;
	q.push(node);

	check[node] = true;
	dist[node] = 0;

	while (!q.empty()) {
		node = q.front();
		q.pop();

		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];

			if (!check[next]) {
				dist[next] = dist[node] + 1;

				check[next] = true;

				q.push(next);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		a[u].push_back(v);
	}

	bfs(X);

	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			cnt++;
			cout << i << '\n';
		}
	}

	if (cnt == 0)
		cout << -1 << '\n';

	return 0;
}