#include <iostream>
#include <queue>

using namespace std;

/* �ʿ��� ���������� ����! */

int a[100][100];	// ���� ǥ��� �迭
int g[100][100];	// ���� �׷� ǥ��� �迭
int d[100][100];	// �Ÿ��� ��� ���� �迭

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	// �迭 �ʱ�ȭ!
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];

	/* �׷��� ǥ���ϴ� �۾��̴� */

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == 1 && g[i][j] == 0) {
				g[i][j] = ++cnt;
				queue<pair<int, int>> q;

				q.push(make_pair(i, j));

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;

					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						// ���� ���ڰ� ���� ���� �ִ°�?
						if (0 <= nx && nx < N && 0 <= ny && ny < N) {
							if (a[nx][ny] == 1 && g[nx][ny] == 0) {
								g[nx][ny] = cnt;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}

	/* �� �׷����κ��� �ּ� �Ÿ� Ž�� �����̴� */

	int ans = -1;

	// ������ ������ŭ ������
	for (int l = 1; l <= cnt; l++) {
		queue<pair<int, int>> q;

		// �ش� �׷쿡 ���� �ڱ� �ڽ��� �Ÿ��� 0���� �����,
		// ���� Ž�� �׷�(l)�� �����ϸ� queue�� push�Ѵ�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				d[i][j] = -1;	// �� �׷츶�� �ڱ� �׷��� �����ϰ� �̷��� �ʱ�ȭ!

				if (g[i][j] == l) {
					q.push(make_pair(i, j));
					d[i][j] = 0;
				}
			}
		}

		// �� �׷����κ��� �� ���ڿ� ���� �Ÿ��� ��´�.
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < N && 0 <= ny && ny < N) {
					// ���� �湮���� �ʾ� �ش� �׷����κ����� �Ÿ� ������ ���� �ʾҴٸ�
					if (d[nx][ny] == -1) {
						d[nx][ny] = d[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}

		// �ּ� �Ÿ��� �ǽð����� ��� �������� ���̴�.
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				// ���� �׷�(l)�� �ƴ� �ٸ� �׷��� ������ ����!
				if (a[i][j] == 1 && g[i][j] != l)
					if (ans == -1 || d[i][j] - 1 < ans)
						ans = d[i][j] - 1;
	}

	cout << ans << '\n';

	return 0;
}