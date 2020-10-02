#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[200][200];
bool check[200][200];

// 나이트의 탐색 방향
int dr[6] = { -2, -2, 0, 0, 2, 2 };
int dc[6] = { -1, 1, -2, 2, -1, 1 };

int N;	// 체스판의 크기
int r1, c1, r2, c2;

void bfs(int r, int c) {
	queue<pair<int, int>> q;

	q.push(make_pair(r, c));
	check[r][c] = true;

	// 초기 자기 자신은 0회
	board[r][c] = 0;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;

		q.pop();

		for (int k = 0; k < 6; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// 다음 이동 위치가 범위 내에 있다면
			if (0 <= nr && nr < N && 0 <= nc && nc < N) {
				// 그리고 방문하지 않았다면
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