#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int a[100][100];
int d[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<int> v;	// 차례로 넓이 입력받기!
int M, N, K;

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));

	d[x][y] = cnt;

	int area = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
					area += 1;
				}
			}
		}
	}

	v.push_back(area);
}

int main() {
	cin >> M >> N >> K;

	// 배열 초기화
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = 1;
			d[i][j] = 0;
		}
	}

	// 좌표 입력 받아 직사각형 그리기!
	for (int k = 0; k < K; k++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = M - y2; i < M - y1; i++)
			for (int j = x1; j < x2; j++)
				if (a[i][j] != 0)
					a[i][j] = 0;
	}

	int cnt = 0;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (a[i][j] == 1 && d[i][j] == 0)
				bfs(i, j, ++cnt);

	sort(v.begin(), v.end());

	cout << cnt << endl;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	cout << endl;

	return 0;
}