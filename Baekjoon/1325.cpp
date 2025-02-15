#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adjacencies;	// 인접 리스트
vector<int> answer;
vector<bool> visited;

void bfs(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int nowNode = q.front();
		q.pop();

		for (int i : adjacencies[nowNode]) {
			if (!visited[i]) {
				visited[i] = true;
				answer[i]++;	// 방문 횟수 증가
				q.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	adjacencies.resize(N + 1);
	answer.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;

		adjacencies[S].push_back(E);
	}

	visited.resize(N + 1);

	for (int node = 1; node <= N; node++) {
		fill(visited.begin(), visited.end(), false);

		bfs(node);
	}

	int maxVal = 0;

	for (int node = 1; node <= N; node++) {
		maxVal = max(maxVal, answer[node]);
	}

	for (int node = 1; node <= N; node++) {
		if (answer[node] == maxVal) {
			cout << node << " ";
		}
	}

	cout << '\n';

	return 0;
}