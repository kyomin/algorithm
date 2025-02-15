#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int d[50][50];	// 섬의 번호 기입용 행렬
int a[50][50];	// Land의 위치 기입용 행렬

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// 시작 점(x, y) , 단지 번호 cnt, 너비 w, 높이 h
void bfs(int x, int y, int cnt, int width, int height) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	// 우선 해당 시작 좌표에 섬의 번호 붙이기.
	d[x][y] = cnt;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < height && 0 <= ny && ny < width) {
				// 조건을 만족하는가? => 즉, 연결 조건을 만족하는가?
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

		// 배열 d 초기화
		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
				d[i][j] = 0;
			
		// 배열 a 초기화
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
			{
				int num;
				cin >> num;

				a[i][j] = num;
			}
		}

		// 탐색 시작!
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				// 아직 방문하지 않았다면
				if (a[i][j] == 1 && d[i][j] == 0)
					bfs(i, j, ++cnt, w, h);

		// 마지막 섬의 번호(총 섬의 개수) 출력!
		cout << cnt << '\n';
	}

	return 0;
}