#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int MAX = 51;
const int INF = 987654321;
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int N;
int map[MAX][MAX];
int visit[MAX][MAX];

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int r = 0; r < N; r++) {
		string s;
		cin >> s;

		for (int c = 0; c < s.size(); c++)
			map[r][c] = (int)(s[c] - '0');
	}

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			visit[r][c] = INF;
	
	// 시작점에 대한 처리
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visit[0][0] = 0;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			// 범위 내에 없다면
			if (!isInside(nr, nc)) continue;

			// 흰 방인 경우
			if (map[nr][nc] == 1) {
				if (visit[nr][nc] > visit[r][c]) {
					visit[nr][nc] = visit[r][c];
					q.push(make_pair(nr, nc));
				}
			}

			// 검은 방인 경우
			if (map[nr][nc] == 0) {
				if (visit[nr][nc] > visit[r][c] + 1) {
					visit[nr][nc] = visit[r][c] + 1;
					q.push(make_pair(nr, nc));
				}
			}
		}
	}

	cout << visit[N - 1][N - 1] << '\n';

	return 0;
}