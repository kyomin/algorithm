#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 절대 나올 수 없는 경로 값
const int INF = 1000000000;

int dist[103][103];

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		pair<int, int> position[103];	// 각 정점의 좌표
		cin >> n;

		memset(dist, 0, sizeof(dist));

		// dist 배열 초기화
		// 1 : home, n+2 : 도착지
		for (int i = 1; i <= (n + 2); i++)
			for (int j = 1; j <= (n + 2); j++)
				dist[i][j] = (i == j) ? 0 : INF;

		
		// 간선 정보들 입력 받기
		for (int node = 1; node <= (n + 2); node++) {
			int x, y;
			cin >> x >> y;

			position[node] = make_pair(x, y);

			// 현재까지 입력된 다른 노드들과 거리 비교하여 간선 놓기
			for (int prevNode = 1; prevNode < node; prevNode++) {
				// 거리 계산
				int distance = abs(position[prevNode].first - x) + abs(position[prevNode].second - y);

				// 1000 이하인 거리만 간선 놓는다
				if(distance <= 1000)
					dist[prevNode][node] = min(dist[prevNode][node], distance);
			}
		}

		// 플로이드 와샬 알고리즘 적용
		for (int k = 1; k <= (n + 2); k++)
			for (int i = 1; i <= (n + 2); i++)
				for (int j = 1; j <= (n + 2); j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		// 목적지까지 갈 수 있는 경우
		if (dist[1][n + 2] != INF)
			cout << "happy" << '\n';
		else
			cout << "sad" << '\n';
	}

	return 0;
}