#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

vector<int> a[501];	// ���� ����Ʈ
bool check[501];
set<int> connectedNodes[501];	// �� ������ ������ ������ ������

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

		// �ش� �������� �ٸ� �������� �� �͵�� ���� �͵� insert!
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