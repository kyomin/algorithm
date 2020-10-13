#include <iostream>
#include <vector>

using namespace std;

// 인접리스트 정의
vector<int> a[101];
bool check[101];
int result = 0;

void DFS(int node) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];

		if (!check[next]) {
			result += 1;
			DFS(next);
		}
	}
}

int main() {
	// 컴퓨터 대수, 연결 쌍의 개수
	int N, P;
	cin >> N >> P;

	for (int i = 0; i < P; i++) {
		int u, v;
		cin >> u >> v;

		a[u].push_back(v);
		a[v].push_back(u);
	}

	DFS(1);

	cout << result << '\n';

	return 0;
}