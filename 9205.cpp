#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100 + 2;	// 편의점 최대 100, 출발점, 도착점

int N;
vector<int> graph[MAX];	// 인접 행렬
bool visited[MAX];

// 맨해튼 거리
int getDistance(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

// dfs
void dfs(int node) {
	visited[node] = true;	// 방문 체크

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		
		if (!visited[next])
			dfs(next);
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		// 초기화
		for (int i = 0; i < MAX; i++)
			graph[i].clear();
		memset(visited, false, sizeof(visited));

		cin >> N;
		vector<pair<int, int>> coordinate;	// 좌표(coordinate)

		// 출발점: 0, 도착점: N+1
		for (int i = 0; i < N + 2; i++) {
			int x, y;
			cin >> x >> y;

			coordinate.push_back(make_pair(x, y));
		}

		// 맥주 20병으로 갈 수 있는 거리 내에 있으면 그래프에 추가
		for (int i = 0; i < N + 2; i++) {
			for (int j = i + 1; j < N + 2; j++) {
				if (getDistance(coordinate[i], coordinate[j]) <= (50 * 20)) {
					// 양방향 그래프
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		// 출발점 0에서부터
		dfs(0);

		// 도착점 N+1에 도달했는가?
		if (visited[N + 1])
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}

	return 0;
}