#include <iostream>
#include <queue>

using namespace std;

char map[250][250];
bool check[250][250];

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int R, C;
int totalSheep = 0, totalWolf = 0;

void bfs(int r, int c) {
	int sheep = 0, wolf = 0;

	queue<pair<int, int>> q;

	q.push(make_pair(r, c));

	check[r][c] = true;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;

		q.pop();

		if (map[r][c] == 'v')
			wolf++;
		else if (map[r][c] == 'o')
			sheep++;

		// 상하좌우 탐색
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// 범위 내에 있고
			if (0 <= nr && nr < R && 0 <= nc && nc < C) {
				// 울타리(벽)가 아니고 아직 방문하지 않았다면
				if (map[nr][nc] != '#' && !check[nr][nc]) {
					q.push(make_pair(nr, nc));
					check[nr][nc] = true;
				}
			}
		}
	}

	if (sheep > wolf)
		totalSheep += sheep;
	else
		totalWolf += wolf;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;

	for (int r = 0; r < R; r++)
		cin >> map[r];

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] != '#' && !check[r][c])
				bfs(r, c);
		}
	}

	cout << totalSheep << ' ' << totalWolf << '\n';

	return 0;
}