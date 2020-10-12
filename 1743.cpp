#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int a[101][101];
bool check[101][101];
int N, M, K;
int big = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int x, int y) {
	check[x][y] = true;

	queue<pair<int, int>> q;

	// 탐색 지점부터 해당 영역의 음식물 개수를 센다
	int cnt = 1;

	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (1 <= nx && nx <= N && 1 <= ny && ny <= M) {
				if (a[nx][ny] == 1 && check[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
					cnt++;
				}
			}
		}
	}

	big = max(big, cnt);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;

		a[x][y] = 1;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (a[i][j] == 1 && check[i][j] == false)
				BFS(i, j);

	cout << big << endl;

	return 0;
}