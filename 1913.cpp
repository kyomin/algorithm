#include <iostream>

using namespace std;

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

int dp[1000][1000];
int N, target;

bool isInside(int r, int c) {
	if (1 <= r && r <= N && 1 <= c && c <= N)
		return true;
	else
		return false;
}

int main() {
	int out_r, out_c;
	cin >> N >> target;

	// ���� ���� �� ó��
	if (N == 1) {
		cout << 1 << '\n';
		cout << 1 << ' ' << 1 << '\n';

		return 0;
	}

	int dir = 0;		// ó�� ������ �Ʒ���
	int r = 1, c = 1;
	dp[r][c] = N * N;

	while (true) {
		if (dp[r][c] == target) {
			out_r = r;
			out_c = c;
		}

		int nr = r + dr[dir];
		int nc = c + dc[dir];

		// �̹� �湮�� ���̰ų� ������ ����� ������ ư��
		if (!isInside(nr, nc) || dp[nr][nc] != 0) {
			dir += 1;

			if (dir > 3)
				dir = 0;

			nr = r + dr[dir];
			nc = c + dc[dir];

			// ���� ������ Ʋ���µ�, �̹� �湮�� ���̶�� ������ ư��.
			if (dp[nr][nc] != 0)
				break;

			dp[nr][nc] = dp[r][c] - 1;
			r = nr;
			c = nc;

			continue;
		}

		dp[nr][nc] = dp[r][c] - 1;
		r = nr;
		c = nc;
	}

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			if (c != N)
				cout << dp[r][c] << ' ';
			else
				cout << dp[r][c] << '\n';

	cout << out_r << ' ' << out_c << '\n';

	return 0;
}