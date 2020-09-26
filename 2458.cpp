#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

vector<int> a[501];	// 인접 리스트
bool check[501];
set<int> connectedNodes[501];	// 한 정점에 들어오고 나가는 정점들

void dfs(int node) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];

		if (!check[next])
			dfs(next);
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;

		cin >> u >> v;

		a[u].push_back(v);
	}

	for (int node = 1; node <= N; node++) {
		memset(check, false, sizeof(check));

		dfs(node);

		// 해당 정점에서 다른 정점으로 간 것들과 들어온 것들 insert!
		for (int i = 1; i <= N; i++) {
			if (check[i]) {
				connectedNodes[node].insert(i);
				connectedNodes[i].insert(node);
			}
		}
	}

	int cnt = 0;
	
	for (int node = 1; node <= N; node++) {
		if (connectedNodes[node].size() == N)
			cnt++;
	}

	cout << cnt << '\n';
	
	return 0;
}