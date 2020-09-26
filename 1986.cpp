#include <iostream>

using namespace std;

char board[1001][1001];
bool isSafe[1001][1001];

// ����Ʈ�� �̵� ���
int moveKnightR[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int moveKnightC[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// ���� �̵� ���
int moveQueenR[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int moveQueenC[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };


int R, C;

// ����Ʈ �����̱�
void moveKnight(int r, int c) {
	for (int k = 0; k < 8; k++) {
		int nr = moveKnightR[k];
		int nc = moveKnightC[k];

		// ���� ���� �ִٸ�
		if (1 <= nr && nr <= R && 1 <= nc && nc <= C) {
			// �׸��� �� �ڸ��� �ٸ� ���� ���ٸ�
			if (board[nr][nc] == 'E') {
				// �������� �ʴٰ� ǥ��!
				isSafe[nr][nc] = false;
			}
		}
	}
}

// �� �����̱� (where : ��� ��������?)
void moveQueen(int r, int c, int where) {
	int nr = r + moveQueenR[where];
	int nc = c + moveQueenC[where];

	// ���� ���� �ִٸ�
	if (1 <= nr && nr <= R && 1 <= nc && nc <= C) {
		// �׸��� �� �ڸ��� �ٸ� ���� ���ٸ�
		if (board[nr][nc] == 'E') {
			// �������� �ʴٰ� ǥ��!
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
			isSafe[r][c] = true;	// �ϴ� �� �����ϴٰ� ǥ��
			board[r][c] = 'E';		// �� �� : E��� ǥ��
		}
	}

	// �� �Է�!
	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = 'Q';
		isSafe[r][c] = false;
	}

	// ����Ʈ �Է�!
	cin >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = 'K';
		isSafe[r][c] = false;
	}

	// �� �Է�!
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