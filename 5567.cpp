#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;

vector<int> vt[501];
bool check[501] = { false, };
int dist[501] = { 0, };

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		vt[u].push_back(v);
		vt[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	check[1] = true;

	while (!q.empty()) {
		int n = q.front();

		q.pop();

		for (int k = 0; k < vt[n].size(); k++) {
			if (!check[vt[n][k]]) {
				q.push(vt[n][k]);
				dist[vt[n][k]] = dist[n] + 1;
				check[vt[n][k]] = true;
			}
		}
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++)
		if (dist[i] == 1 || dist[i] == 2)
			cnt++;

	cout << cnt << '\n';

	return 0;
}