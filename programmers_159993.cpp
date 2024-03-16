#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Point {
	int r;
	int c;
};

const int dr[4] = { 1, -1, 0, 0 };
const int dc[4] = { 0, 0, 1, -1 };

int R;
int C;

bool isInside(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C)
		return false;

	return true;
}

int solution(vector<string> maps) {
	int answer = -1;

	R = maps.size();
	C = maps[0].length();

	vector<vector<int>> dist(R, vector<int>(C, 0));

	Point start, exit, lever;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (maps[r][c] == 'S') {
				start.r = r;
				start.c = c;				
			}

			if (maps[r][c] == 'E') {
				exit.r = r;
				exit.c = c;
			}

			if (maps[r][c] == 'L') {
				lever.r = r;
				lever.c = c;
			}
		}
	}

	// BFS 탐색
	queue<Point> q;

	q.push(start);

	bool isLeverUp = false;

	while (!q.empty()) {
		Point point = q.front();
		
		int r = point.r;
		int c = point.c;

		q.pop();

		// 레버가 올라간 상태에서 탈출구를 만났을 때
		if (isLeverUp && maps[r][c] == 'E') {
			answer = dist[r][c];

			break;
		}

		// 아직 레버가 안올라간 상태에서 레버를 만났을 때
		if (!isLeverUp && maps[r][c] == 'L') {
			isLeverUp = true;

			int time = dist[r][c];

			// 큐와 걸린 시간 배열 dist 초기화
			q = queue<Point>();

			fill(dist.begin(), dist.end(), vector<int>(C, 0));

			// 레버까지 걸린 시간 설정
			dist[r][c] = time;
		}

		// 다음 방문지를 위해 상하좌우 탐색
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// 범위 체크
			if (!isInside(nr, nc)) continue;

			// 방문한 곳이라면
			if (dist[nr][nc] != 0) continue;

			// 벽이라면
			if (maps[nr][nc] == 'X') continue;

			Point next;
			next.r = nr;
			next.c = nc;

			q.push(next);

			dist[nr][nc] = dist[r][c] + 1;
		}
	}

	return answer;
}