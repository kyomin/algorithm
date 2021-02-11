#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 16;
const int dr[] = { 1, -1, 0, 0 };
const int dc[] = { 0, 0, 1, -1 };

string map[MAX];
bool check[MAX][MAX];
int ans = 0;

bool isInside(int r, int c) {
	if (0 <= r && r < MAX && 0 <= c && c < MAX)
		return true;

	return false;
}

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));

	check[r][c] = true;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		// 상하좌우 탐색
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// 다음 탐색 지점이 범위를 벗어나는 경우
			if (!isInside(nr, nc)) continue;

			// 다음 탐색 지점이 벽인 경우
			if (map[nr][nc] == '1') continue;

			// 이미 방문한 경우
			if (check[nr][nc]) continue;

			// 다음 탐색 지점이 목표 지점인 경우에 해답을 찾은 경우이므로
			if (map[nr][nc] == '3') {
				ans = 1;
				return;
			}

			// 위의 경우에 걸리지 않는다면 탐색을 계속 진행한다.
			q.push(make_pair(nr, nc));
			check[nr][nc] = true;
		}
	}
}

int main() {
	for (int t = 1; t <= 10; t++) {
		int T;
		cin >> T;

		memset(check, false, sizeof(check));
		ans = 0;

		for (int r = 0; r < MAX; r++)
			cin >> map[r];

		for (int r = 0; r < MAX; r++)
			for (int c = 0; c < MAX; c++)
				if (map[r][c] == '2')
					bfs(r, c);

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}