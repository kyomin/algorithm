#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int tomato[1000][1000];
int dist[1000][1000];
bool check[1000][1000];

int N, M;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;

	queue<pair<int, int>> q;
	bool is_it_zero = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];

			// 처음의 토마토 위치를 큐에 담는다.
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));

				// 토마토가 위치한 거리는 0
				dist[i][j] = 0;

				// 그리고 방문했다고 check!
				check[i][j] = true;
			}

			// 안 익은 토마토를 센다
			if (tomato[i][j] == 0)
				is_it_zero = true;

			check[i][j] = false;
			dist[i][j] = 0;
		}
	}

	// 안 익은 토마토가 없다면
	if (!is_it_zero) {
		cout << 0 << '\n';
		return 0;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (!check[nx][ny] && tomato[nx][ny] == 0) {
					q.push(make_pair(nx, ny));

					dist[nx][ny] = dist[x][y] + 1;

					check[nx][ny] = true;
				}
			}
		}
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 안 익은 토마토인데 방문을 안 했다면
			if (tomato[i][j] == 0 && !check[i][j]) {
				cout << -1 << '\n';
				return 0;
			}

			result = max(dist[i][j], result);
		}
	}

	cout << result << '\n';

	return 0;
}