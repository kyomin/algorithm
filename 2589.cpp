#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int answer = 0;
int Y, X;

char map[50][50];
int dist[50][50];
bool check[50][50];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
	queue<pair<int, int>> q;

	q.push(make_pair(y, x));

	check[y][x] = true;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (0 <= nx && nx < X && 0 <= ny && ny < Y) {
				if (!check[ny][nx] && map[ny][nx] == 'L') {
					q.push(make_pair(ny, nx));
					dist[ny][nx] = dist[y][x] + 1;
					check[ny][nx] = true;

					// �ִܰŸ� ����
					answer = max(dist[y][x] + 1, answer);
				}
			}
		}
	}
}

int main() {
	cin >> Y >> X;

	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			// ������ �߰��ϴ� ���� Ž�� ����
			if (map[y][x] == 'L') {
				bfs(y, x);

				// ���� ������ ��ǥ�� �������� Ž���ϴ� ���̹Ƿ� ������ ���� �ʱ�ȭ
				memset(check, false, sizeof(check));
				memset(dist, 0, sizeof(dist));
			}
		}
	}

	cout << answer << '\n';

	return 0;
}