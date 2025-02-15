#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct position {
	int row, col, height;
};

int tomato[100][100][100];
int dist[100][100][100];
bool check[100][100][100];

int R, C, H;

const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };
const int dh[2] = { 1, -1 };

bool isInPlane(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;
	else
		return false;
}

bool isInHeight(int h) {
	if (0 <= h && h < H)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> C >> R >> H;

	bool isZero = true;
	queue<position> q;

	for (int height = 0; height < H; height++) {
		for (int row = 0; row < R; row++) {
			for (int col = 0; col < C; col++) {
				cin >> tomato[row][col][height];

				// 처음의 토마토 위치들을 큐에 담는다.
				if (tomato[row][col][height] == 1) {
					q.push({ row, col, height });

					// 방문 체크!
					check[row][col][height] = true;
				}

				// 안 익은 토마토가 입력됐다면 안 익은 토마토가 존재하므로
				if (tomato[row][col][height] == 0)
					isZero = false;
			}
		}
	}

	// map을 다 입력했는데, 안 익은 토마토가 없다면
	if (isZero) {
		cout << 0 << '\n';
		return 0;
	}

	// BFS 시작 !!
	while (!q.empty()) {
		int row = q.front().row;
		int col = q.front().col;
		int height = q.front().height;

		q.pop();

		// 1. 평면 상 하 좌 우 탐색 !!
		for (int k = 0; k < 4; k++) {
			int nr = row + dr[k];
			int nc = col + dc[k];

			// 평면 범위를 벗어나는 경우
			if (!isInPlane(nr, nc))
				continue;

			// 이미 방문한 경우
			if (check[nr][nc][height])
				continue;

			// 안 익은 토마토가 아니라면
			if (tomato[nr][nc][height] != 0)
				continue;

			// 위의 검증 과정을 다 통과했으면
			q.push({ nr, nc, height });

			dist[nr][nc][height] = dist[row][col][height] + 1;

			check[nr][nc][height] = true;
		}

		// 2. 수직 위 아래 탐색 !!
		for (int k = 0; k < 2; k++) {
			int nh = height + dh[k];

			// 수직 범위를 벗어나는 경우
			if (!isInHeight(nh))
				continue;

			// 이미 방문한 경우
			if (check[row][col][nh])
				continue;

			// 안 익은 토마토가 아니라면
			if (tomato[row][col][nh] != 0)
				continue;

			// 위의 검증 과정을 다 통과했으면
			q.push({ row, col, nh });

			dist[row][col][nh] = dist[row][col][height] + 1;

			check[row][col][nh] = true;
		}
	}

	int result = 0;

	for (int height = 0; height < H; height++) {
		for (int row = 0; row < R; row++) {
			for (int col = 0; col < C; col++) {
				// 안 익은 토마토인데, 방문을 안 했다면 다 익히지 못한 것이다
				if (tomato[row][col][height] == 0 && !check[row][col][height]) {
					cout << -1 << '\n';
					return 0;
				}

				result = max(dist[row][col][height], result);
			}
		}
	}

	cout << result << '\n';

	return 0;
}