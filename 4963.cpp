#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int d[50][50];	// ���� ��ȣ ���Կ� ���
int a[50][50];	// Land�� ��ġ ���Կ� ���

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// ���� ��(x, y) , ���� ��ȣ cnt, �ʺ� w, ���� h
void bfs(int x, int y, int cnt, int width, int height) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	// �켱 �ش� ���� ��ǥ�� ���� ��ȣ ���̱�.
	d[x][y] = cnt;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < height && 0 <= ny && ny < width) {
				// ������ �����ϴ°�? => ��, ���� ������ �����ϴ°�?
				if (a[nx][ny] == 1 && d[nx][ny] == 0)
				{
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	while (true) {
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		int cnt = 0;

		// �迭 d �ʱ�ȭ
		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
				d[i][j] = 0;
			
		// �迭 a �ʱ�ȭ
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
			{
				int num;
				cin >> num;

				a[i][j] = num;
			}
		}

		// Ž�� ����!
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				// ���� �湮���� �ʾҴٸ�
				if (a[i][j] == 1 && d[i][j] == 0)
					bfs(i, j, ++cnt, w, h);

		// ������ ���� ��ȣ(�� ���� ����) ���!
		cout << cnt << '\n';
	}

	return 0;
}