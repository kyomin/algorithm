#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> a[10];	// ���� ����Ʈ
bool check[10];		// ��� �湮 ����
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
			// ���� ��带 �������� ����Ŀ� ���� �޶��� �� �����Ƿ�
			memset(check, false, sizeof(check));
			dfs(n, 1);
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
}