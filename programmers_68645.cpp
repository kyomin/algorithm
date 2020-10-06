#include <string>
#include <vector>

using namespace std;

// 0 : �Ʒ�, 1 : ������, 2 : ���� �밢�� ��
const int dr[] = { 1, 0, -1 };
const int dc[] = { 0, 1, -1 };

int R, C;
int dp[1000][1000];

bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;
	else
		return false;
}

vector<int> solution(int n) {
	if (n == 1)
		return { 1 };

	vector<int> answer;
	R = n, C = n;
	int dir = 0;	// ó�� ������ �Ʒ���
	int r = 0, c = 0;
	dp[r][c] = 1;

	while (true) {
		int nr = r + dr[dir];
		int nc = c + dc[dir];

		// �̹� �湮�� ���̰ų� ������ ����� ������ ư��.
		if (!isInside(nr, nc) || dp[nr][nc] != 0) {
			dir += 1;

			if (dir > 2)
				dir = 0;

			// ���� ������ Ʋ���µ�, �̹� �湮�� ���̶�� �� ä�� ���̴�.
			nr = r + dr[dir];
			nc = c + dc[dir];

			if (dp[nr][nc] != 0)
				break;

			dp[nr][nc] = dp[r][c] + 1;
			r = nr;
			c = nc;

			continue;
		}

		dp[nr][nc] = dp[r][c] + 1;
		r = nr;
		c = nc;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (dp[i][j] != 0)
				answer.push_back(dp[i][j]);

	return answer;
}