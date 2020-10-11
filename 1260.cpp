#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check[1001];
vector<int> a[1001];
queue<int> q;	// bfs 구현용 큐
vector<int> v1;	// dfs 순서용 벡터
vector<int> v2; // bfs 순서용 벡터

void dfs(int node) {
	check[node] = true;
	v1.push_back(node);

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];

		// 아직 방문하지 않은 노드라면
		if (check[next] == false)
			dfs(next);
	}
}

void bfs(int node) {
	check[node] = true;
	q.push(node);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		v2.push_back(x);

		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];

			if (check[y] == false) {
				check[y] = true;
				q.push(y);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= 1000; i++)
		sort(a[i].begin(), a[i].end());

	dfs(V);

	for (int i = 1; i <= 1000; i++)
		check[i] = false;

	bfs(V);

	int len1 = v1.size();
	int len2 = v2.size();

	for (int i = 0; i < len1; i++)
		cout << v1[i] << ' ';

	cout << '\n';

	for (int i = 0; i < len2; i++)
		cout << v2[i] << ' ';

	cout << '\n';

	return 0;
}