#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool check[101] = { false, };
vector<int> vt[101];
int relation[101] = { 0, };

void DFS(int node, int cnt) {
	check[node] = true;
	relation[node] = cnt;

	for (int i = 0; i < vt[node].size(); i++) {
		int next = vt[node][i];

		if (!check[next])
			DFS(next, cnt + 1);
	}
}

int main() {
	int start_node, end_node;
	cin >> N;
	cin >> start_node >> end_node;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		vt[u].push_back(v);
		vt[v].push_back(u);
	}

	DFS(start_node, 0);

	if (relation[end_node] != 0)
		cout << relation[end_node] << '\n';
	else
		cout << -1 << '\n';

	return 0;
}