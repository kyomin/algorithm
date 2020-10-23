#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 300;
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int map[MAX][MAX];
int temp[MAX][MAX];
bool check[MAX][MAX];
int N, M;

void mapToTemp() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			temp[r][c] = map[r][c];
}

void tempToMap() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			map[r][c] = temp[r][c];
}

// 범위 내에 있는가?
bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < M)
		return true;

	return false;
}

// 인접한 바닷물의 면 만큼 녹여준다.
void melt() {
	mapToTemp();

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (map[r][c] != 0) {
				int zero_cnt = 0;

				for (int k = 0; k < 4; k++) {
					int nr = r + dr[k];
					int nc = c + dc[k];

					if (!isInside(nr, nc)) continue;
					if (map[nr][nc] != 0) continue;

					zero_cnt++;
				}

				temp[r][c] -= zero_cnt;

				if (temp[r][c] <= 0)
					temp[r][c] = 0;
			}
		}
	}

	tempToMap();
}

// 바닷물이 다 녹았는가?
bool isMelted() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			if (map[r][c] != 0)
				return false;

	return true;
}

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	check[r][c] = true;

	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (!isInside(nr, nc)) continue;
			if (map[nr][nc] == 0) continue;
			if (check[nr][nc]) continue;

			check[nr][nc] = true;
			q.push(make_pair(nr, nc));
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> map[r][c];

	// 애초에 처음부터 다 녹아있는 경우
	if (isMelted()) {
		cout << 0 << '\n';
		return 0;
	}

	int year = 0;

	while (true) {
		memset(check, false, sizeof(check));

		int cnt = 0;

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (map[r][c] != 0 && !check[r][c]) {
					cnt++;
					bfs(r, c);
				}
			}
		}

		if (cnt >= 2)
			break;

		year++;
		melt();

		if (isMelted()) {
			year = 0;
			break;
		}
	}

	cout << year << '\n';

	return 0;
}