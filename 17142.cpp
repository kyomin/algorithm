#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int dr[] = { 1, -1, 0, 0 };
const int dc[] = { 0, 0, 1, -1 };

struct Point {
	int r, c, d;
};

int N, M;
int map[50][50];
Point virus[10];
int virus_cnt;

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

int countbits(int n) {
	int cnt = 0;

	while (n) {
		// 맨 오른쪽에 있는 비트를 판단한다.
		if (n & 1) cnt++;

		// 오른쪽 쉬프트를 1만큼 하게 되면 맨 오른쪽 비트가 떨어져 나간다.
		n = n >> 1;	
	}

	return cnt;
}

int solve() {
	int ret = INF;

	// virus_cnt 개의 바이러스 중에서 M개를 선택한다.
	// 비트연산자를 통해 부분집합을 구해나간다.
	for (int subset = 0; subset < (1 << virus_cnt); subset++) {
		// virus_cnt에 대한 모든 부분집합에 대해서 M만큼 비트에 1이 켜진 것들만 찾아내야 한다.
		if (countbits(subset) == M) {
			bool visited[50][50] = { false };
			int dist = 0;
			queue<Point> q;

			// M만큼 선택한 바이러스를 큐에 담는다.
			for (int i = 0; i < virus_cnt; i++) {
				if (subset & (1 << i)) {
					visited[virus[i].r][virus[i].c] = true;
					q.push(virus[i]);
				}
			}

			// BFS 탐색 시작!
			while (!q.empty()) {
				Point cur = q.front();
				q.pop();

				if (map[cur.r][cur.c] != 2)
					dist = max(dist, cur.d);

				// 상하좌우 진행
				for (int k = 0; k < 4; k++) {
					int nr = cur.r + dr[k];
					int nc = cur.c + dc[k];

					// 범위를 벗어난 경우
					if (!isInside(nr, nc))
						continue;

					// 이미 방문한 경우
					if (visited[nr][nc])
						continue;

					// 새로 가고자 하는 위치가 벽이라면
					if (map[nr][nc] == 1)
						continue;

					visited[nr][nc] = true;
					q.push({ nr, nc, cur.d + 1 });
				}
			}

			// 빈칸을 다 채우지 못했는지 체크
			bool is_full = true;
			for (int r = 0; r < N; r++)
				for (int c = 0; c < N; c++)
					if (map[r][c] == 0 && visited[r][c] == false)
						is_full = false;

			if (is_full)
				ret = min(ret, dist);
		}
	}

	if (ret == INF)
		return -1;
	
	return ret;
}

int main() {
	cin >> N >> M;

	virus_cnt = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];

			// 바이러스일 경우
			if (map[r][c] == 2) {
				virus[virus_cnt++] = { r, c };
			}
		}
	}

	cout << solve() << endl;

	return 0;
}