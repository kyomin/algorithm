#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[200][200];
bool check[200][200];

// ����Ʈ�� Ž�� ����
int dr[6] = { -2, -2, 0, 0, 2, 2 };
int dc[6] = { -1, 1, -2, 2, -1, 1 };

int N;	// ü������ ũ��
int r1, c1, r2, c2;

void bfs(int r, int c) {
	queue<pair<int, int>> q;

	q.push(make_pair(r, c));
	check[r][c] = true;

	// �ʱ� �ڱ� �ڽ��� 0ȸ
	board[r][c] = 0;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;

		q.pop();

		for (int k = 0; k < 6; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// ���� �̵� ��ġ�� ���� ���� �ִٸ�
			if (0 <= nr && nr < N && 0 <= nc && nc < N) {
				// �׸��� �湮���� �ʾҴٸ�
				if (!check[nr][nc]) {
					q.push(make_pair(nr, nc));
					board[nr][nc] = board[r][c] + 1;
					check[nr][nc] = true;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	memset(board, -1, sizeof(board));

	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;

	bfs(r1, c1);

	cout << board[r2][c2] << '\n';

	return 0;
}