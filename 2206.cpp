#include <iostream>
#include <queue>

using namespace std;

struct position {
	// flag는 벽을 부순 적이 있는지의 여부를 체크한다.
	// 0 : 안 부숨, 1 : 부숨
	int r, c, flag;
};

int R, C;
char map[1001][1001];
int dist[1001][1001][2];

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

// map의 범위 내인지를 판별하는 함수
bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;
	else
		return false;
}

int bfs() {
	queue<position> q;
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int flag = q.front().flag;

		q.pop();

		// 끝에 도달한 경우
		if (r == R - 1 && c == C - 1) 
			return dist[r][c][flag];


		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (!isInside(nr, nc)) continue;
			if (dist[nr][nc][flag]) continue;

			// 벽이 아니라 그냥 갈 수 있는 곳이라면
			if (map[nr][nc] == '0') {
				dist[nr][nc][flag] = dist[r][c][flag] + 1;
				q.push({ nr, nc, flag });
			}

			// 다음으로 갈 위치가 벽이면서 아직 벽을 부순 적이 없다면
			if (map[nr][nc] == '1' && flag == 0) {
				// 벽을 부수고, flag를 1로 바꾼다
				dist[nr][nc][1] = dist[r][c][flag] + 1;
				q.push({ nr, nc, 1 });
			}
		}
	}

	// BFS 탐색을 끝마쳤는데도 끝에 도달하지 못한 경우
	return -1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;

	for (int r = 0; r < R; r++)
		cin >> map[r];

	cout << bfs() << '\n';

	return 0;
}