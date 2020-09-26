#include <iostream>

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

// 나이트 움직이기
void moveKnight(int r, int c) {
	for (int k = 0; k < 8; k++) {
		int nr = moveKnightR[k];
		int nc = moveKnightC[k];

		// 범위 내에 있다면
		if (1 <= nr && nr <= R && 1 <= nc && nc <= C) {
			// 그리고 그 자리에 다른 말이 없다면
			if (board[nr][nc] == 'E') {
				// 안전하지 않다고 표시!
				isSafe[nr][nc] = false;
			}
		}
	}
}

// 퀸 움직이기 (where : 어느 방향으로?)
void moveQueen(int r, int c, int where) {
	int nr = r + moveQueenR[where];
	int nc = c + moveQueenC[where];

	// 범위 내에 있다면
	if (1 <= nr && nr <= R && 1 <= nc && nc <= C) {
		// 그리고 그 자리에 다른 말이 없다면
		if (board[nr][nc] == 'E') {
			// 안전하지 않다고 표시!
			isSafe[nr][nc] = false;
		}
		else {
			return;
		}
	}
	else {
		return;
	}

	moveQueen(nr, nc, where);
}

int main() {
	int Q, K, P;

	cin >> R >> C;

	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			isSafe[r][c] = true;	// 일단 다 안전하다고 표기
			board[r][c] = 'E';		// 빈 곳 : E라고 표기
		}
	}

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
				for (int k = 0; k < 8; k++) {
					moveQueen(r, c, k);
				}
				continue;
			}
		}
	}

	int ans = 0;

	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (isSafe[r][c])
				ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}