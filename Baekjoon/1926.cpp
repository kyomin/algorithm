#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int map[500][500];
int label[500][500];

int R, C;
int ans = 0;

bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;
	
	return false;
}

void bfs(int r, int c, int cnt) {
	int sum = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	label[r][c] = cnt;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (!isInside(nr, nc)) continue;

			if (map[nr][nc] == 1 && label[nr][nc] == 0) {
				q.push(make_pair(nr, nc));
				label[nr][nc] = cnt;
				sum += 1;
			}
		}
	}

	ans = max(ans, sum);
}

int main() {
	cin >> R >> C;

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cin >> map[r][c];

	int cnt = 0;

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			if (map[r][c] == 1 && label[r][c] == 0)
				bfs(r, c, ++cnt);

	cout << cnt << '\n' << ans << '\n';

	return 0;
}