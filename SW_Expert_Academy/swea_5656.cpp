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

// 벽돌 제거 후 아래로 떨어뜨리기
void dropDown() {
	for (int c = 0; c < C; c++) {
		for (int r = R - 1; r >= 1; r--) {
			if (map[r][c] != 0)
				continue;

			// 빈 공간 발견 시 그 시점부터 위의 벽돌을 찾아 내려준다.
			for (int k = r - 1; k >= 0; k--) {
				if (map[k][c] != 0) {
					map[r][c] = map[k][c];	// 벽돌 내려주고
					map[k][c] = 0;			// 빈 공간으로 만들어주기
					break;
				}
			}
		}
	}
}

// 벽돌 제거
void breakWalls(int r, int c) {
	// 벽돌이 아닌 빈 공간이면 탐색 종료!
	if (map[r][c] == 0)
		return;

	// 벽돌 숫자가 곧 영향을 미치는 범위이다.
	int range = map[r][c];

	// 벽돌을 깨부순다.
	map[r][c] = 0;

	// 연쇄적으로 영향을 미치는 다른 벽돌 깨 부수면서 탐색 시작!
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
	copyArr(map, copy_map);			// 현 단계에서의 map의 형상을 저장한다.

	// 벽돌을 선택하는 횟수를 다 채웠다면 정산한다.
	if (n == N) {
		int cnt = 0;

		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				if (map[r][c] != 0)
					cnt++;

		ans = min(ans, cnt);

		return;
	}

	// 0 ~ (C-1) 사이에 구슬을 N번 투하하는 모든 경우
	for (int c = 0; c < C; c++) {
		int r = 0;

		// c의 위치에서 아래로 구슬을 투하해 가장 먼저 만나는 벽을 찾는 과정이다.
		while (isInside(r, c) && map[r][c] == 0)
			r++;

		// 대상 벽돌을 찾았다면 부수는 작업 시작!
		breakWalls(r, c);

		// 벽돌을 다 부순 후에, 떨어뜨려 빈 공간을 채워주는 작업을 한다.
		dropDown();

		// 다음 횟수로!
		dfs(n + 1);

		// 위에서 저장했던 이 단계에서의 map의 형상을 복원한다.
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