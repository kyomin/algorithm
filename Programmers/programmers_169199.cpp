#include <string>
#include <vector>
#include <queue>
#define MAX 100
using namespace std;

const int INF = 987654321;
int R, C;
pair<int, int> start;
bool visited[MAX][MAX];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;

	return false;
}

int solution(vector<string> board) {
	int answer = INF;
	queue<pair<pair<int, int>, int>> q;	// firsr: 좌표, second: 이동 횟수
	
	R = board.size();
	C = board[0].length();
	
	// 로봇 위치를 처음 시작 위치로 추출
	for (int r = 0; r < R; r++) {
		bool found = false;

		for (int c = 0; c < C; c++) {
			if (board[r][c] == 'R') {
				start = { r, c };
				found = true;
				break;
			}
		}

		if (found)
			break;
	}

	q.push({ {start.first, start.second}, 0 });
	visited[start.first][start.second] = true;

	// bfs 탐색 시작
	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		// 목표 지점에 도달한 경우
		if (board[r][c] == 'G')
			answer = min(answer, cnt);

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// 다음 위치가 범위를 벗어나거나 장애물을 만난 경우
			if (!isInside(nr, nc) || board[nr][nc] == 'D')
				continue;

			// 쭉 이동 로직
			while (true) {
				nr += dr[k];
				nc += dc[k];

				// 위와 마찬가지로 다음으로 가지 못해 멈추는 경우
				if (!isInside(nr, nc) || board[nr][nc] == 'D') {
					nr -= dr[k];
					nc -= dc[k];
					break;
				}
			}

			// 쭉 이동해서 마지막에 멈춘 위치에 대해
			if (visited[nr][nc])
				continue;

			q.push({ {nr, nc}, cnt + 1 });
			visited[nr][nc] = true;
		}
	}

	// 목표 지점에 도달하지 못한 경우
	if (answer == INF)
		return -1;

	return answer;
}