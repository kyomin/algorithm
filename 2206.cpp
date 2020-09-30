#include <iostream>
#include <queue>

using namespace std;

struct position {
	// flag�� ���� �μ� ���� �ִ����� ���θ� üũ�Ѵ�.
	// 0 : �� �μ�, 1 : �μ�
	int r, c, flag;
};

int R, C;
char map[1001][1001];
int dist[1001][1001][2];

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

// map�� ���� �������� �Ǻ��ϴ� �Լ�
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

		// ���� ������ ���
		if (r == R - 1 && c == C - 1) 
			return dist[r][c][flag];


		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (!isInside(nr, nc)) continue;
			if (dist[nr][nc][flag]) continue;

			// ���� �ƴ϶� �׳� �� �� �ִ� ���̶��
			if (map[nr][nc] == '0') {
				dist[nr][nc][flag] = dist[r][c][flag] + 1;
				q.push({ nr, nc, flag });
			}

			// �������� �� ��ġ�� ���̸鼭 ���� ���� �μ� ���� ���ٸ�
			if (map[nr][nc] == '1' && flag == 0) {
				// ���� �μ���, flag�� 1�� �ٲ۴�
				dist[nr][nc][1] = dist[r][c][flag] + 1;
				q.push({ nr, nc, 1 });
			}
		}
	}

	// BFS Ž���� �����ƴµ��� ���� �������� ���� ���
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