#include <iostream>
#include <cstring>

using namespace std;

// dp[y][x] : (y, x) ������ �� �����ϴ� ����� ����
int dp[500][500];
int map[500][500];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int m, n;

int dfs(int y, int x) {
	// ���� ������ ���������� ��� 1���� �߰��� ���̴�.
	if (y == 0 && x == 0) {
		return 1;
	}

	// ���� �湮���� ���� ���̶��
	if (dp[y][x] == -1) {
		dp[y][x] = 0;

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (map[y][x] < map[ny][nx]) {
					dp[y][x] += dfs(ny, nx);
				}
			}
		}
	}

	return dp[y][x];
}

int main() {
	memset(dp, -1, sizeof(dp));

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(m - 1, n - 1) << '\n';

	return 0;
}