#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int N, R, C;
int map[15][12];
int ans = INF;

// copy a to b
void copyArr(int a[][12], int b[][12]) {
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			b[r][c] = a[r][c];
}

bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;

	return false;
}

// ���� ���� �� �Ʒ��� ����߸���
void dropDown() {
	for (int c = 0; c < C; c++) {
		for (int r = R - 1; r >= 1; r--) {
			if (map[r][c] != 0)
				continue;

			// �� ���� �߰� �� �� �������� ���� ������ ã�� �����ش�.
			for (int k = r - 1; k >= 0; k--) {
				if (map[k][c] != 0) {
					map[r][c] = map[k][c];	// ���� �����ְ�
					map[k][c] = 0;			// �� �������� ������ֱ�
					break;
				}
			}
		}
	}
}

// ���� ����
void breakWalls(int r, int c) {
	// ������ �ƴ� �� �����̸� Ž�� ����!
	if (map[r][c] == 0)
		return;

	// ���� ���ڰ� �� ������ ��ġ�� �����̴�.
	int range = map[r][c];

	// ������ ���μ���.
	map[r][c] = 0;

	// ���������� ������ ��ġ�� �ٸ� ���� �� �μ��鼭 Ž�� ����!
	for (int i = 0; i < range; i++) {
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k] * i;
			int nc = c + dc[k] * i;

			if (!isInside(nr, nc))
				continue;

			if (map[nr][nc] == 0)
				continue;

			breakWalls(nr, nc);
		}
	}
}

void dfs(int n) {
	int copy_map[15][12] = { 0 };
	copyArr(map, copy_map);			// �� �ܰ迡���� map�� ������ �����Ѵ�.

	// ������ �����ϴ� Ƚ���� �� ä���ٸ� �����Ѵ�.
	if (n == N) {
		int cnt = 0;

		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				if (map[r][c] != 0)
					cnt++;

		ans = min(ans, cnt);

		return;
	}

	// 0 ~ (C-1) ���̿� ������ N�� �����ϴ� ��� ���
	for (int c = 0; c < C; c++) {
		int r = 0;

		// c�� ��ġ���� �Ʒ��� ������ ������ ���� ���� ������ ���� ã�� �����̴�.
		while (isInside(r, c) && map[r][c] == 0)
			r++;

		// ��� ������ ã�Ҵٸ� �μ��� �۾� ����!
		breakWalls(r, c);

		// ������ �� �μ� �Ŀ�, ����߷� �� ������ ä���ִ� �۾��� �Ѵ�.
		dropDown();

		// ���� Ƚ����!
		dfs(n + 1);

		// ������ �����ߴ� �� �ܰ迡���� map�� ������ �����Ѵ�.
		copyArr(copy_map, map);
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		ans = INF;
		cin >> N >> C >> R;

		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				cin >> map[r][c];

		dfs(0);

		cout << "#" << test_case << ' ' << ans << '\n';
	}

	return 0;
}