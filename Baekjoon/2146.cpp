#include <iostream>
#include <queue>

using namespace std;

/* 필요한 전역변수들 선언! */

int a[100][100];	// 육지 표기용 배열
int g[100][100];	// 육지 그룹 표기용 배열
int d[100][100];	// 거리를 담기 위한 배열

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	// 배열 초기화!
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];

	/* 그룹을 표기하는 작업이다 */

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == 1 && g[i][j] == 0) {
				g[i][j] = ++cnt;
				queue<pair<int, int>> q;

				q.push(make_pair(i, j));

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;

					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						// 인접 격자가 영역 내에 있는가?
						if (0 <= nx && nx < N && 0 <= ny && ny < N) {
							if (a[nx][ny] == 1 && g[nx][ny] == 0) {
								g[nx][ny] = cnt;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}

	/* 각 그룹으로부터 최소 거리 탐색 과정이다 */

	int ans = -1;

	// 육지의 개수만큼 돌린다
	for (int l = 1; l <= cnt; l++) {
		queue<pair<int, int>> q;

		// 해당 그룹에 대해 자기 자신의 거리는 0으로 만들고,
		// 현재 탐색 그룹(l)을 만족하면 queue에 push한다
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				d[i][j] = -1;	// 각 그룹마다 자기 그룹을 제외하고 이렇게 초기화!

				if (g[i][j] == l) {
					q.push(make_pair(i, j));
					d[i][j] = 0;
				}
			}
		}

		// 각 그룹으로부터 각 격자에 대한 거리를 담는다.
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < N && 0 <= ny && ny < N) {
					// 아직 방문하지 않아 해당 그룹으로부터의 거리 셋팅을 하지 않았다면
					if (d[nx][ny] == -1) {
						d[nx][ny] = d[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}

		// 최소 거리를 실시간으로 계속 셋팅해줄 것이다.
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				// 현재 그룹(l)이 아닌 다른 그룹을 만나는 순간!
				if (a[i][j] == 1 && g[i][j] != l)
					if (ans == -1 || d[i][j] - 1 < ans)
						ans = d[i][j] - 1;
	}

	cout << ans << '\n';

	return 0;
}