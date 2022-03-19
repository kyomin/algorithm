#include <iostream>
#include <queue>
using namespace std;

const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };
int R, C;
int sheep, wolf;
char map[250][250];
bool check[250][250];

bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;

	return false;
}

void bfs(int r, int c) {
	int s = 0;	// 양의 수
	int w = 0;	// 늑대의 수

	if (map[r][c] == 'k')
		s++;

	if (map[r][c] == 'v')
		w++;

	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	check[r][c] = true;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (!isInside(nr, nc))
				continue;

			if (map[nr][nc] == '#')
				continue;

			if (check[nr][nc])
				continue;

			check[nr][nc] = true;
			q.push(make_pair(nr, nc));

			if (map[nr][nc] == 'k')
				s++;

			if (map[nr][nc] == 'v')
				w++;
		}
	}

	if (s > w)
		sheep += s;
	else
		wolf += w;
}

int main() {
	cin >> R >> C;

	for (int r = 0; r < R; r++)
		cin >> map[r];

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			if (map[r][c] != '#' && !check[r][c])
				bfs(r, c);

	cout << sheep << ' ' << wolf << endl;

	return 0;
}