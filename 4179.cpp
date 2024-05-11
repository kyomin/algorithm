#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

char map[MAX][MAX];

int fire_visited[MAX][MAX];
int person_visited[MAX][MAX];

int R, C;
int pr, pc;	// 캐릭터의 초기 위치

const int dr[4] = { 1, -1, 0, 0 };
const int dc[4] = { 0, 0, 1, -1 };
const int INF = 987654321;

bool isInside(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C)
		return false;

	return true;
}

bool isEdge(int r, int c) {
	if (r == R - 1 || c == C - 1 || r == 0 || c == 0)
		return true;

	return false;
}

int main() {
	queue<pair<int, int>> q;

	cin >> R >> C;

	// 불의 도달 거리를 최대로 설정
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			fire_visited[r][c] = INF;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];

			if (map[r][c] == 'F') {
				fire_visited[r][c] = 1;

				q.push({ r,c });
			}

			if (map[r][c] == 'J') {
				pr = r;
				pc = c;
			}
				
		}
	}

	// 불에 대한 BFS 탐색
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// 범위를 벗어났다면
			if (!isInside(nr, nc))
				continue;

			// 방문한 곳이라면
			if (fire_visited[nr][nc] != INF)
				continue;

			// 벽이라면
			if (map[nr][nc] == '#')
				continue;

			fire_visited[nr][nc] = fire_visited[r][c] + 1;

			q.push({ nr, nc });
		}
	}

	// 캐릭터에 대한 BFS 탐색 및 정답 구하기
	int ans = 0;

	person_visited[pr][pc] = 1;
	
	q.push({ pr, pc });

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;

		q.pop();

		// 가장자리라면 탈출
		if (isEdge(r, c)) {
			ans = person_visited[r][c];

			break;
		}

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// 범위를 벗어났다면
			if (!isInside(nr, nc))
				continue;

			// 방문한 곳이라면
			if (person_visited[nr][nc])
				continue;

			// 벽이라면
			if (map[nr][nc] == '#')
				continue;

			// 불이 먼저 도달했다면
			if (fire_visited[nr][nc] <= person_visited[r][c] + 1)
				continue;

			person_visited[nr][nc] = person_visited[r][c] + 1;

			q.push({ nr, nc });
		}
	}

	if (ans)
		cout << ans << endl;
	else
		cout << "IMPOSSIBLE" << endl;

	return 0;
}