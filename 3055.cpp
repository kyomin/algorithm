#include <iostream>
#include <queue>

using namespace std;

char map[50][50];
int dist[50][50];

int dc[4] = { 1, 0, -1, 0 };
int dr[4] = { 0, 1, 0, -1 };

int R, C;

int main() {
	int targetR, targetC;
	cin >> R >> C;

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cin >> map[r][c];

	queue<pair<int, int>> q;

	// ���� ���� �ִ� ������ �ִ´�. => �׷��� ������ ����ġ�� �̵��� �� �ִ��� ������ �Ǵ� ����
	for (int r = 0; r < R; r++) 
		for (int c = 0; c < C; c++) 
			if (map[r][c] == '*')
				q.push(make_pair(r, c));

	// ����ġ�� ��ġ�� �ִ´�.
	for (int r = 0; r < R; r++) 
		for (int c = 0; c < C; c++)
			if (map[r][c] == 'S')
				q.push(make_pair(r, c));

	// ���� ��ġ�� ã�´�.
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			if (map[r][c] == 'D')
				targetR = r, targetC = c;

	// BFS
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// ���� ���� �ְ�
			if (0 <= nr && nr < R && 0 <= nc && nc < C) {
				if (map[r][c] == '*') {	// ���� ���� ���̰�
					if (map[nr][nc] == '.') {	// ���� ��ġ�� �� ĭ�̶��
						map[nr][nc] = '*';	// ���� ä���
						q.push(make_pair(nr, nc));
					}
				}
				else {	// ���� ����ġ�̰�
					if (map[nr][nc] == '.') {	// ���� ��ġ�� �� ĭ�̶��
						map[nr][nc] = 'S';	// ���� ä���
						dist[nr][nc] = dist[r][c] + 1;
						q.push(make_pair(nr, nc));
					}
					else if (map[nr][nc] == 'D') {
						dist[nr][nc] = dist[r][c] + 1;
					}
				}
			}
		}
	}

	if (dist[targetR][targetC] == 0)
		cout << "KAKTUS" << endl;
	else
		cout << dist[targetR][targetC] << endl;

	return 0;
}