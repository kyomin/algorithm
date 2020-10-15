#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[100001];
bool check[100001];
int parent[100001];
int depth[100001];

void BFS() {
	queue<int> q;

	// 루트 노드에 대한 초기화
	depth[1] = 0;
	check[1] = true;
	parent[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < a[x].size(); i++) {
			if (!check[a[x][i]]) {
				depth[a[x][i]] = depth[x] + 1;
				check[a[x][i]] = true;
				parent[a[x][i]] = x;
				q.push(a[x][i]);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	// 노드 입력 받기
	for (int i = 0; i < N - 1; i++) {
		int u, v;

		cin >> u >> v;

		a[u].push_back(v);
		a[v].push_back(u);
	}

	BFS();

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';

	return 0;
}