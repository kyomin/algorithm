#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int a[100][100];	// ������ ���� ����
int d[100][100];	// ���� ���� ����
bool check[100][100];	// �湮 ���ο� ����

// �� �� �� �� Ž���� �迭
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// �� / �� ����
int N;

// ���� ���� �ʱ�ȭ �Լ�
void Init() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			check[i][j] = false;
			d[i][j] = 1;
		}
	}
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (d[nx][ny] == 1 && !check[nx][ny]) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int max_area = 0;
	int max_safe_area = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];

			// ���� ���� ������ ���� ������ ��´�.
			max_area = max(max_area, a[i][j]);
		}
	}

	for (int k = 0; k <= max_area; k++) {
		int cnt = 0;

		Init();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (a[i][j] <= k)
					d[i][j] = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (d[i][j] == 1 && !check[i][j]) {
					BFS(i, j);
					cnt += 1;
				}
			}
		}

		max_safe_area = max(max_safe_area, cnt);
	}

	cout << max_safe_area << '\n';

	return 0;
}