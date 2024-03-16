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

	// BFS Ž��
	queue<Point> q;

	q.push(start);

	bool isLeverUp = false;

	while (!q.empty()) {
		Point point = q.front();
		
		int r = point.r;
		int c = point.c;

		q.pop();

		// ������ �ö� ���¿��� Ż�ⱸ�� ������ ��
		if (isLeverUp && maps[r][c] == 'E') {
			answer = dist[r][c];

			break;
		}

		// ���� ������ �ȿö� ���¿��� ������ ������ ��
		if (!isLeverUp && maps[r][c] == 'L') {
			isLeverUp = true;

			int time = dist[r][c];

			// ť�� �ɸ� �ð� �迭 dist �ʱ�ȭ
			q = queue<Point>();

			fill(dist.begin(), dist.end(), vector<int>(C, 0));

			// �������� �ɸ� �ð� ����
			dist[r][c] = time;
		}

		// ���� �湮���� ���� �����¿� Ž��
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// ���� üũ
			if (!isInside(nr, nc)) continue;

			// �湮�� ���̶��
			if (dist[nr][nc] != 0) continue;

			// ���̶��
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