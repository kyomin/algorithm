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

		// �����¿� Ž��
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// ���� Ž�� ������ ������ ����� ���
			if (!isInside(nr, nc)) continue;

			// ���� Ž�� ������ ���� ���
			if (map[nr][nc] == '1') continue;

			// �̹� �湮�� ���
			if (check[nr][nc]) continue;

			// ���� Ž�� ������ ��ǥ ������ ��쿡 �ش��� ã�� ����̹Ƿ�
			if (map[nr][nc] == '3') {
				ans = 1;
				return;
			}

			// ���� ��쿡 �ɸ��� �ʴ´ٸ� Ž���� ��� �����Ѵ�.
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