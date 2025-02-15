#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dist[100][100];	// �������� ����� ��´�.
int a[100][100];	// �̷��� ������ ��´�.
bool check[100][100];	// �湮 ���θ� ��´�.

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	// bfs�� ���� ť ����
	queue<pair<int, int>> q;

	// N : ��, M : ��
	int N, M;
	cin >> N >> M;

	// �̷� ���� �迭�� �ʱ�ȭ!
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) {
			a[i][j] = (int)(str[j] - '0');
			check[i][j] = false;
		}
	}

	// ���� ���� ���� �۾�!
	q.push(make_pair(0, 0));
	check[0][0] = true;
	dist[0][0] = 1;

	// Ž�� ����!
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (check[nx][ny] == false && a[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = true;
				}
			}
		}
	}

	cout << dist[N - 1][M - 1] << endl;

	return 0;
}