#include <vector>
#include <queue>

using namespace std;

int a[100][100];	// ���� ǥ���
int d[100][100];	// �湮 üũ��

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int X, Y;

int bfs(int x, int y, int cnt, int color) {
	int area = 0;

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	d[x][y] = cnt;
	area += 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// �����¿� Ž��
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			// ���� ���� ���� �ִ°�?
			if (0 <= nx && nx < X && ny >= 0 && ny < Y) {
				// ������ �����ϴ°�?
				if (a[nx][ny] == color && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
					area += 1;
				}
			}
		}
	}

	return area;
}


// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	X = m;	// ��
	Y = n;	// ��

	// �迭 a, d �ʱ�ȭ
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = 0;
			a[i][j] = picture[i][j];
		}
	}

	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			// ���� ĥ�����ְ�, ���� �湮���� �ʾ�����
			if (a[i][j] != 0 && d[i][j] == 0) {
				// Ž�� ����!
				int temp_area = bfs(i, j, ++number_of_area, a[i][j]);

				// �ִ� ���� ����
				if (temp_area > max_size_of_one_area)
					max_size_of_one_area = temp_area;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}