#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 18;	// roundup log(2, 100000)

int N, M;
int parent[50000][MAX];	// parent[i][k] : i의 2^k번째 부모
int depth[50000];			// 정점의 깊이 (루트의 깊이는 0)
vector<int> adj[50000];	// 인접 리스트

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// dfs로 트리 제작하며 parent[i][0], depth 배열 채움
void makeTreeByDfs(int cur) {
	for (int next : adj[cur]) {
		if (depth[next] == -1) {
			parent[next][0] = cur;
			depth[next] = depth[cur] + 1;
			makeTreeByDfs(next);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 트리 정보 입력
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;

		u--;
		v--;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 배열 초기화
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	depth[0] = 0;

	// 트리 만들기
	makeTreeByDfs(0);

	// parent 배열 채움
	for (int j = 0; j < MAX - 1; j++)
		for (int i = 1; i < N; i++)	// 0이 루트 노드이므로 1부터 시작
			if (parent[i][j] != -1)	// 부모가 채워져 있다면 부모의 부모 정보를 채운다
				parent[i][j + 1] = parent[parent[i][j]][j];

	// 쿼리 입력받기
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		u--;
		v--;

		// depth[u] >= depth[v]가 되도록 필요에 따라 u, v를 스왑!
		if (depth[u] < depth[v])
			swap(u, v);

		int diff = depth[u] - depth[v];

		// 깊이 차(diff)를 없애며 u를 이동시킴
		for (int j = 0; diff; j++) {
			if (diff % 2)
				u = parent[u][j];

			diff /= 2;
		}

		// u와 v가 다르면 동시에 일정 높이만큼 위로 이동시킴
		if (u != v) {
			// 높이 2^17, 2^16, .... , 2^2, 2^1, 1 순으로 시도
			for (int j = MAX - 1; j >= 0; j--) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}

			// 마지막엔 두 정점 u, v의 부모가 같으므로 한 번 더 올림
			u = parent[u][0];
		}

		// LCA 출력
		cout << u + 1 << '\n';
	}

	return 0;
}