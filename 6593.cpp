#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

struct Position {
	int l;
	int r;
	int c;
};

const int MAX = 30;
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };
const int dl[] = { 1, -1 };

char map[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
bool check[MAX][MAX][MAX];
int L, R, C;

bool isInside(int l, int r, int c) {
	if (0 <= l && l < L && 0 <= r && r < R && 0 <= c && c < C)
		return true;

	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) break;

		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));

		Position start;
		Position end;

		for (int l = 0; l < L; l++) {
			for (int r = 0; r < R; r++) {
				string s;
				cin >> s;

				for (int c = 0; c < s.size(); c++) {
					map[l][r][c] = s[c];

					if (map[l][r][c] == 'S')
						start = { l, r, c };

					if (map[l][r][c] == 'E')
						end = { l, r, c };
				}
			}
		}

		// ���� ���� ���� ó��
		queue<Position> q;
		q.push(start);
		check[start.l][start.r][start.c] = true;

		// BFS ����!
		while (!q.empty()) {
			int l = q.front().l;
			int r = q.front().r;
			int c = q.front().c;
			q.pop();

			// �ϴ� �����¿쿡 ���� 2���� Ž��
			for (int k = 0; k < 4; k++) {
				int nl = l;
				int nr = r + dr[k];
				int nc = c + dc[k];

				// ��(����)�� ������ ��� ���
				if (!isInside(nl, nr, nc)) continue;

				// �����ִ� ĭ�� ���
				if (map[nl][nr][nc] == '#') continue;

				// �̹� �湮�� ���
				if (check[nl][nr][nc]) continue;

				dist[nl][nr][nc] = dist[l][r][c] + 1;
				check[nl][nr][nc] = true;
				q.push({ nl, nr, nc });
			}

			// �� �Ʒ��� ���� 3���� Ž��
			for (int k = 0; k < 2; k++) {
				int nl = l + dl[k];
				int nr = r;
				int nc = c;

				// ��(����)�� ������ ��� ���
				if (!isInside(nl, nr, nc)) continue;

				// �����ִ� ĭ�� ���
				if (map[nl][nr][nc] == '#') continue;

				// �̹� �湮�� ���
				if (check[nl][nr][nc]) continue;

				dist[nl][nr][nc] = dist[l][r][c] + 1;
				check[nl][nr][nc] = true;
				q.push({ nl, nr, nc });
			}
		}

		// end�� �������� ���� ���
		if (!check[end.l][end.r][end.c])
			cout << "Trapped!" << '\n';
		else
			cout << "Escaped in " << dist[end.l][end.r][end.c] << " minute(s)." << '\n';
	}

	return 0;
}