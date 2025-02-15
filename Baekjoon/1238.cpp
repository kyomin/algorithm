#include <iostream>
#include <algorithm>

using namespace std;

// 절대 나올 수 없는 경로 값
const int INF = 1000000000;

int dist[1001][1001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, X;
	cin >> N >> M >> X;

	// dist 배열 초기화
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = (i == j) ? 0 : INF;

	// 간선 정보 입력 받기
	for (int m = 0; m < M; m++) {
		int a, b, c;
		cin >> a >> b >> c;

		dist[a][b] = min(dist[a][b], c);
	}

	// 플로이드 와샬 알고리즘 적용
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int result = 0;

	for (int i = 1; i <= N; i++) {
		if (i == X)
			continue;

		// X까지 가는데 걸리는 시간 + X에서 오는데 걸리는 시간
		int time = dist[i][X] + dist[X][i];

		result = max(result, time);
	}

	cout << result << '\n';

	return 0;
}