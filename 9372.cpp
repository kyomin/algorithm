#include <iostream>
#include <vector>

using namespace std;

vector<int> vt[1001];
int cnt = 0;
bool check[1001] = { false, };

// 전역 변수 초기화
void Init() {
	for (int i = 1; i <= 1000; i++) {
		vt[i].clear();
		check[i] = false;
	}

	cnt = 0;
}

void DFS(int node) {
	check[node] = true;

	if (node != 1)
		cnt++;

	for (int i = 0; i < vt[node].size(); i++) {
		// 아직 방문 안 했다면
		if (!check[vt[node][i]]) 
			DFS(vt[node][i]);
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		Init();

		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;

			vt[u].push_back(v);
			vt[v].push_back(u);
		}

		DFS(1);

		cout << cnt << endl;
	}
}