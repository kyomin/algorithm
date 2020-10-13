#include <iostream>
#include <queue>

using namespace std;

bool check[300][300];

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// 시작 좌표, 목표 좌표, 체스판 사이즈
int BFS(pair<int, int> start, pair<int, int> target, int l) {
	// 배열 초기화
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
			check[i][j] = false;

	// first : 좌표, second : 횟수
	queue<pair<pair<int, int>, int>> q;

	// 첫 시작 좌표 넣기!
	q.push(make_pair(start, 0));

	check[start.first][start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curCnt = q.front().second;

		q.pop();

		// 목표 지점에 도달했다면 횟수 반환하며 종료
		if (x == target.first && y == target.second)
			return curCnt;

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			// 체스판 범위 내에 있다면!
			if (0 <= nx && nx < l && 0 <= ny && ny < l) {
				if (check[nx][ny] == false)
				{
					q.push(make_pair(make_pair(nx, ny), curCnt + 1));
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int l, sX, sY, tX, tY;
		cin >> l >> sX >> sY >> tX >> tY;

		cout << BFS(make_pair(sX, sY), make_pair(tX, tY), l) << endl;
	}

	return 0;
}