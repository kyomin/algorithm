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
	queue<pair<pair<int, int>, int>> q;	// firsr: ��ǥ, second: �̵� Ƚ��
	
	R = board.size();
	C = board[0].length();
	
	// �κ� ��ġ�� ó�� ���� ��ġ�� ����
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

	// bfs Ž�� ����
	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		// ��ǥ ������ ������ ���
		if (board[r][c] == 'G')
			answer = min(answer, cnt);

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// ���� ��ġ�� ������ ����ų� ��ֹ��� ���� ���
			if (!isInside(nr, nc) || board[nr][nc] == 'D')
				continue;

			// �� �̵� ����
			while (true) {
				nr += dr[k];
				nc += dc[k];

				// ���� ���������� �������� ���� ���� ���ߴ� ���
				if (!isInside(nr, nc) || board[nr][nc] == 'D') {
					nr -= dr[k];
					nc -= dc[k];
					break;
				}
			}

			// �� �̵��ؼ� �������� ���� ��ġ�� ����
			if (visited[nr][nc])
				continue;

			q.push({ {nr, nc}, cnt + 1 });
			visited[nr][nc] = true;
		}
	}

	// ��ǥ ������ �������� ���� ���
	if (answer == INF)
		return -1;

	return answer;
}