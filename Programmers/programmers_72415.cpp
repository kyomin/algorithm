#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

struct Point {
	int row;
	int col;
	int cnt;	// 조작 횟수
};

vector<vector<int>> Board;	// board 정보의 전역 변수화

const int dr[4] = { 1, -1, 0, 0 };
const int dc[4] = { 0, 0, 1, -1 };

/*	
	src에서 dest로 가는 최소 조작 횟수를 bfs 탐색한다

	@param src		시작 위치
	@param dest		도착 위치

	@return			최소 조작 횟수
*/
int bfs(Point src, Point dest) {
	bool visited[4][4] = { false };
	queue<Point> q;

	q.push(src);

	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		if (curr.row == dest.row && curr.col == dest.col)
			return curr.cnt;
		
		for (int i = 0; i < 4; i++) {
			int nr = curr.row + dr[i];
			int nc = curr.col + dc[i];

			// 경게 확인
			if (nr < 0 || nr>3 || nc < 0 || nc>3)
				continue;

			// 방향키로 이동하는 경우
			if (!visited[nr][nc]) {
				visited[nr][nc] = true;
				q.push({ nr, nc, curr.cnt + 1 });
			}

			// Ctrl + 방향키로 이동하는 경우
			for (int j = 0; j < 2; j++) {
				if (Board[nr][nc] != 0)
					break;

				if (
					nr + dr[i] < 0 ||
					nr + dr[i] > 3 ||
					nc + dc[i] < 0 ||
					nc + dc[i] > 3
					)
					break;

				nr += dr[i];
				nc += dc[i];
			}

			if (!visited[nr][nc]) {
				visited[nr][nc] = true;
				q.push({ nr, nc, curr.cnt + 1 });
			}
		}
	}
	
	return INF;
}

/*
	순열로 가능한 모든 경우의 수를 구한다

	@param src		현재 위치

	@return			현재 위치부터 시작해서 모든 카드를 제거하는 조작 횟수
*/
int permutate(Point src) {
	int ret = INF;

	for (int num = 1; num <= 6; num++) {
		vector<Point> card;

		// 4 x 4 board 탐색하여 현재 그림카드 위치 저장
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (Board[i][j] == num)
					card.push_back({ i, j, 0 });				

		// 이미 제거되어 그림카드가 없는 경우 skip
		if (card.empty())
			continue;

		// 먼저 삭제할 두 가지 케이스로 나눈다.
		int one = bfs(src, card[0]) + bfs(card[0], card[1]) + 2;
		int two = bfs(src, card[1]) + bfs(card[1], card[0]) + 2;

		// 삭제한 카드 제거
		for (int i = 0; i < 2; i++)
			Board[card[i].row][card[i].col] = 0;
		
		ret = min(ret, one + permutate(card[1]));
		ret = min(ret, two + permutate(card[0]));

		// 보드판 복원
		for (int i = 0; i < 2; i++)
			Board[card[i].row][card[i].col] = num;
	}

	// 모든 카드가 제거되어 있다면
	if (ret == INF)
		return 0;

	return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
	Board = board;

	return permutate({ r, c, 0 });
}