#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dist[100][100];	// 동적으로 비용을 담는다.
int a[100][100];	// 미로의 구조를 담는다.
bool check[100][100];	// 방문 여부를 담는다.

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	// bfs를 위한 큐 정의
	queue<pair<int, int>> q;

	// N : 행, M : 열
	int N, M;
	cin >> N >> M;

	// 미로 관련 배열들 초기화!
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) {
			a[i][j] = (int)(str[j] - '0');
			check[i][j] = false;
		}
	}

	// 시작 점에 대한 작업!
	q.push(make_pair(0, 0));
	check[0][0] = true;
	dist[0][0] = 1;

	// 탐색 시작!
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (check[nx][ny] == false && a[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = true;
				}
			}
		}
	}

	cout << dist[N - 1][M - 1] << endl;

	return 0;
}