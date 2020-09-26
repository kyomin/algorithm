#include <iostream>
#include <queue>

using namespace std;

const int MAX = 50;
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int map[MAX][MAX];
int copy_map[MAX][MAX];
int R, C, T;

pair<int, int> air_cleaner[2];	// 0: 위, 1: 아래

void input() {
	cin >> R >> C >> T;
	int idx = 0;

	for (int row = 0; row < R; row++) {
		for (int col = 0; col < C; col++) {
			cin >> map[row][col];

			if (map[row][col] == -1) {
				air_cleaner[idx].first = row;
				air_cleaner[idx].second = col;
				idx++;
			}
		}
	}
}

// 지도 내부인가?
bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;
	else
		return false;
}

// 2차원 배열 매개 변수는 열의 크기만 지정!
void copyMap(int original[][MAX], int duplicate[][MAX]) {
	for (int row = 0; row < R; row++)
		for (int col = 0; col < C; col++)
			duplicate[row][col] = original[row][col];
}

// 먼지를 확산 시킨다!
void spreadDust() {
	copyMap(map, copy_map);

	for (int row = 0; row < R; row++) {
		for (int col = 0; col < C; col++) {
			// 먼지라면 확산!
			if (map[row][col] != 0 && map[row][col] != -1) {
				int cnt = 0;	// 확산된 방향의 개수
				int val = map[row][col] / 5;	// 확산되는 양

				for (int k = 0; k < 4; k++) {
					int nr = row + dr[k];
					int nc = col + dc[k];

					// 지도 내부를 벗어나면
					if (!isInside(nr, nc)) continue;

					// 공기 청정기가 아니라면 확산 적용
					if (map[nr][nc] != -1) {
						copy_map[nr][nc] += val;
						cnt++;
					}
				}

				copy_map[row][col] -= (cnt*val);
			}
		}
	}

	copyMap(copy_map, map);
}

// 바람으로 먼지를 밀어낸다!
void moveDust() {
	// 공기 청정기의 윗 칸, 아랫 칸을 각각 고려한다.
	int up = 0;
	int down = 1;

	/* 
		윗 칸 
	*/
	// 1. 가장 왼쪽(0, 0)에서 자기 높이까지 땡기기
	for (int i = air_cleaner[up].first - 1; i > 0; i--)
		map[i][0] = map[i - 1][0];

	// 2. 가장 윗줄 왼쪽으로 땡기기
	for (int i = 0; i < C - 1; i++)
		map[0][i] = map[0][i + 1];

	// 3. 가장 오른쪽 위로 땡겨주기
	for (int i = 1; i <= air_cleaner[up].first; i++)
		map[i - 1][C - 1] = map[i][C - 1];

	// 4. 공기 청정기가 위치한 라인 오른쪽으로 떙기기
	for (int i = C - 1; i > 1; i--)
		map[air_cleaner[up].first][i] = map[air_cleaner[up].first][i - 1];

	/*
		아래 칸
	*/
	// 1. 가장 왼족 열 아래서 자기까지 땡기기
	for (int i = air_cleaner[down].first + 1; i < R - 1; i++)
		map[i][0] = map[i + 1][0];

	// 2. 가장 아래쪽 행 왼쪽으로 떙기기
	for (int i = 0; i < C - 1; i++)
		map[R - 1][i] = map[R - 1][i + 1];

	// 3. 가장 오른쪽 열 아래로 땡기기
	for (int i = R - 1; i > air_cleaner[down].first; i--)
		map[i][C - 1] = map[i - 1][C - 1];

	// 4. 아래쪽 공기 청정기가 위치한 라인 오른쪽으로 땡기기
	for (int i = C - 1; i > 1; i--)
		map[air_cleaner[down].first][i] = map[air_cleaner[down].first][i - 1];


	// 공기 청정기로부터 오른쪽으로 나온 것은 정화된 0이다.
	map[air_cleaner[up].first][1] = 0;
	map[air_cleaner[down].first][1] = 0;
}

// 최종적으로 남아있는 먼지의 양을 센다.
int countDust() {
	int sum = 0;

	for (int row = 0; row < R; row++) {
		for (int col = 0; col < C; col++) {
			if (map[row][col] == -1) continue;

			sum += map[row][col];
		}
	}

	return sum;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	for (int t = 0; t < T; t++) {
		spreadDust();
		moveDust();
	}

	cout << countDust() << '\n';

	return 0;
}