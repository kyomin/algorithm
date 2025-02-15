#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> a[10];	// 인접 리스트
bool check[10];		// 노드 방문 여부
int ans = 0;

void init() {
	for (int i = 0; i < 10; i++) 
		a[i].clear();
}

void dfs(int node, int length) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];

		if (!check[next])
			dfs(next, length + 1);
	}

	ans = max(ans, length);
	check[node] = false;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		init();
		ans = 0;
		int N, M;
		cin >> N >> M;

		for (int m = 0; m < M; m++) {
			int u, v;
			cin >> u >> v;

			a[u - 1].push_back(v - 1);
			a[v - 1].push_back(u - 1);
		}

		for (int n = 0; n < N; n++) {
			// 시작 노드를 무엇으로 잡느냐에 따라 달라질 수 있으므로
			memset(check, false, sizeof(check));
			dfs(n, 1);
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
}