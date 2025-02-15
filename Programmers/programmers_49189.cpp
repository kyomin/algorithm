#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> a[50001];	// 인접 리스트
bool check[50001];	// 방문 여부 체크!
int depth[50001];	// 깊이 여부 체크!

void bfs(int node) {
	queue<int> q;

	// 체크해주고!
	check[node] = true;

	q.push(node);

	while (!q.empty()) {
		int n = q.front();

		q.pop();

		for (int i = 0; i < a[n].size(); i++) {
			int next = a[n][i];

			if (!check[next]) {
				// 깊이 체크!
				depth[next] = depth[n] + 1;

				// 방문 체크!
				check[next] = true;

				q.push(next);
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	memset(check, false, sizeof(check));
	memset(depth, 0, sizeof(depth));

	// 인접리스트 초기화
	for (int i = 0; i < edge.size(); i++) {
		a[edge[i][0]].push_back(edge[i][1]);
		a[edge[i][1]].push_back(edge[i][0]);
	}

	bfs(1);

	int maxDepth = *max_element(depth, depth + n + 1);

	for (int i = 1; i <= n; i++)
		if (depth[i] == maxDepth)
			answer++;

	return answer;
}