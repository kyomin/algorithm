#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int a[100][100];	// 지역의 높이 정보
int d[100][100];	// 안전 영역 정보
bool check[100][100];	// 방문 여부용 변수

// 상 하 좌 우 탐색용 배열
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// 행 / 열 길이
int N;

// 전역 변수 초기화 함수
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

			// 가장 높은 지역의 높이 정보를 담는다.
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