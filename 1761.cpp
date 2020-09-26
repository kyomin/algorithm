#include <iostream>
#include <algorithm>

using namespace std;

// 절대 나올 수 없는 경로 값
const int INF = 1000000000;

int main() {
	int **dist;
	int N, M;
	cin >> N;

	// dist 메모리 할당
	dist = new int*[N + 1];

	for (int i = 1; i <= N; i++)
		dist[i] = new int[N + 1];

	// dist 배열 초기화
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = (i == j) ? 0 : INF;

	// 간선 정보 입력 받기
	for (int n = 0; n < N-1; n++) {
		int a, b, c;
		cin >> a >> b >> c;

		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}

	// 플로이드 와샬 알고리즘 적용
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	cin >> M;

	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;

		cout << dist[a][b] << '\n';
	}

	return 0;
}