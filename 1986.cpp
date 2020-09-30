#include <iostream>
#include <cstring>

using namespace std;

char board[1001][1001];
bool isSafe[1001][1001];

// 나이트의 이동 경로
int moveKnightR[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int moveKnightC[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// 퀸의 이동 경로
int moveQueenR[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int moveQueenC[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int R, C;

// 범위 내에 있는가?
bool isInside(int r, int c) {
	if (1 <= r && r <= R && 1 <= c && c <= C)
		return true;
	else
		return false;
}

// 나이트 움직이기
void moveKnight(int r, int c) {
	for (int k = 0; k < 8; k++) {
		int nr = r + moveKnightR[k];
		int nc = c + moveKnightC[k];

		if (!isInside(nr, nc)) continue;

		if (board[nr][nc] != 'E') continue;

		isSafe[nr][nc] = false;
	}
}

// 퀸 움직이기 (where : 어느 방향으로?)
void moveQueen(int r, int c, int where) {
	int nr = r + moveQueenR[where];
	int nc = c + moveQueenC[where];

	while (true) {
		if (!isInside(nr, nc)) break;
		if (board[nr][nc] != 'E') break;

		isSafe[nr][nc] = false;

		nr += moveQueenR[where];
		nc += moveQueenC[where];
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(isSafe, true, sizeof(isSafe));
	memset(board, 'E', sizeof(board));
	int Q, K, P;

	cin >> R >> C;

	// 퀸 입력!
	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = 'Q';
		isSafe[r][c] = false;
	}

	// 나이트 입력!
	cin >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = 'K';
		isSafe[r][c] = false;
	}

	// 폰 입력!
	cin >> P;
	for (int i = 0; i < P; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = 'P';
		isSafe[r][c] = false;
	}

	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (board[r][c] == 'K') {
				moveKnight(r, c);
				continue;
			}

			if (board[r][c] == 'Q') {
				for (int k = 0; k < 8; k++)
					moveQueen(r, c, k);

				continue;
			}
		}
	}

	int ans = 0;

	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++)
			if (isSafe[r][c])
				ans++;

	cout << ans << '\n';

	return 0;
}