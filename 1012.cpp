#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int d[50][50];	// ���� �湮 ���� ���Կ� ���
int a[50][50];	// ������ ��ġ ���Կ� ���

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// ���� ��(x, y) , ������������ ��ȣ cnt, ���� width, ���� height
void bfs(int x, int y, int cnt, int width, int height) {
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));

	// �켱 �ش� ���� ��ǥ�� �������� ��ȣ ���̱�.
	d[y][x] = cnt;

	while (!q.empty()) {
		x = q.front().first;	// ���� �� ��ǥ
		y = q.front().second;	// ���� �� ��ǥ
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < width && 0 <= ny && ny < height) {
				// ������ �����ϴ°�? => ��, ���� ������ �����ϴ°�?
				if (a[ny][nx] == 1 && d[ny][nx] == 0) {
					q.push(make_pair(nx, ny));
					d[ny][nx] = cnt;
				}
			}
		}
	}
}

int main() {
	// �׽�Ʈ ���̽� ���� �Է¹ޱ�
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		// ���������� ī��Ʈ�� ���� ���� ����
		int cnt = 0;

		// M : ����, N : ����, K : ������ ����
		int M, N, K;

		cin >> M >> N >> K;

		// �迭 d�� a�� �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				d[i][j] = 0;
				a[i][j] = 0;
			}
		}

		// �迭 a�� ���� ��ġ ����!
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			a[y][x] = 1;
		}

		// Ž�� ����!
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				// ���� �湮���� �ʾҴٸ�
				if (a[i][j] == 1 && d[i][j] == 0)
					bfs(j, i, ++cnt, M, N);


		// ������ ������������ ��ȣ(�� ������ ����) ���!
		cout << cnt << '\n';
	}

	return 0;
}