#include <iostream>
#include <queue>

using namespace std;

const int INF = 987654321;

const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

struct Point {
	int r;
	int c;
	int d;	// 상어가 이동한 거리
};

int map[20][20];
int N;

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

int solve(int r, int c) {
	int ret = 0;
	int size = 2;	// 초기 크기는 2
	int cnt = 2;	// 상어가 커지기 위해 먹어야 할 물고기 수
	Point minPt = { r, c, 0 };	// 이동할 상어 위치! 조건에 맞춰 계속 갱신해 나간다.

	do {
		bool visited[20][20] = { false };
		queue<Point> q;
		visited[minPt.r][minPt.c] = true;
		q.push({ minPt.r, minPt.c, 0 });
		minPt.d = INF;

		// BFS 탐색
		while (!q.empty()) {
			Point curr = q.front();
			q.pop();

			/* 탐색을 더 진행할 수 있는지 조건 체크 */

			// minPt를 더 갱신할 필요가 없다.
			if (curr.d > minPt.d) continue;

			// 크기가 큰 물고기는 지날 수 없다
			if (map[curr.r][curr.c] > size) continue;

			// 먹을 수 있는 물고기를 찾았다
			if (map[curr.r][curr.c] != 0 && map[curr.r][curr.c] < size) {
				if (curr.d < minPt.d)
					minPt = curr;	// 상어 위치 갱신
				else if (curr.d == minPt.d) {
					// 거리가 같다면 우선적으로 위에 있는 물고기를 먹는다
					if (curr.r < minPt.r)
						minPt = curr;
					// 여러 마리라면 왼쪽에 있는 물고기 먹기
					else if (curr.r == minPt.r && curr.c < minPt.c)
						minPt = curr;
				}

				// 더 탐색할 이유가 없다. 이 위치에서 다시 시작한다.
				continue;
			}

			for (int k = 0; k < 4; k++) {
				int nr = curr.r + dr[k];
				int nc = curr.c + dc[k];

				if (!isInside(nr, nc)) continue;
				if (visited[nr][nc]) continue;

				visited[nr][nc] = true;
				q.push({ nr, nc, curr.d + 1 });
			}
		} 

		// 조건에 맞춰 먹을 수 있는 물고기를 찾은 경우
		if (minPt.d != INF) {
			ret += minPt.d;
			--cnt;

			if (cnt == 0) {
				size += 1;
				cnt = size;
			}

			map[minPt.r][minPt.c] = 0;	// 먹은 물고기 지워주기
		}
	} while (minPt.d != INF);

	return ret;
}

int main() {
	int init_r, init_c;		// 초기 입력 시의 상어 위치
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				init_r = i;
				init_c = j;
				map[i][j] = 0;
			}
		}
	}

	cout << solve(init_r, init_c) << '\n';

	return 0;
}