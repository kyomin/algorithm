#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N;
int map[20][20];	// 인구를 담는다.
int mark[20][20];	// 지역구를 담는다.

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

void fill(int r, int c, int value) {
	if (!isInside(r, c))
		return;

	if (mark[r][c] != 0)
		return;

	// 빈 공간이면 채우기
	mark[r][c] = value;

	// 상하좌우로 재귀 호출
	fill(r - 1, c, value);
	fill(r + 1, c, value);
	fill(r, c - 1, value);
	fill(r, c + 1, value);
}

int solve() {
	int ret = INF;

	// x, y, d1, d2는 마름모를 만들 수 있는 조건으로 설정하기
	for (int x = 0; x <= N - 3; x++) {
		for (int y = 0; y <= N - 2; y++) {
			for (int d1 = 1; (x + d1 <= N - 2 && y - d1 >= 0); d1++) {
				for (int d2 = 1; (x + d1 + d2 <= N - 1 && y + d2 <= N - 1); d2++) {
					// 여기까지 진입하면, 마름모를 만들 수 있는 모든 조건을 만든 것이다.
					memset(mark, 0, sizeof(mark));

					// 진행 방향에 따라 5로 마킹한다.
					for (int i = 0; i <= d1; i++) {
						mark[x + i][y - i] = 5;
						mark[x + d2 + i][y + d2 - i] = 5;
					}

					for (int i = 0; i <= d2; i++) {
						mark[x + i][y + i] = 5;
						mark[x + d1 + i][y - d1 + i] = 5;
					}

					// 각 꼭짓점에서 그리는 경계선 마킹하기
					for (int r = x - 1; r >= 0; r--)
						mark[r][y] = 1;

					for (int c = y + d2 + 1; c < N; c++)
						mark[x + d2][c] = 2;

					for (int c = y - d1 - 1; c >= 0; c--)
						mark[x + d1][c] = 3;

					for (int r = x + d1 + d2 + 1; r < N; r++)
						mark[r][y - d1 + d2] = 4;

					fill(0, 0, 1);
					fill(0, N - 1, 2);
					fill(N - 1, 0, 3);
					fill(N - 1, N - 1, 4);
					
					// 각 선거구의 인구수를 담기 위한 배열이다.
					int people[6] = { 0 };
					for (int r = 0; r < N; r++)
						for (int c = 0; c < N; c++)
							people[mark[r][c]] += map[r][c];

					people[5] += people[0];

					int min_people = INF;
					int max_people = 0;

					for (int i = 1; i <= 5; i++) {
						min_people = min(min_people, people[i]);
						max_people = max(max_people, people[i]);
					}

					ret = min(ret, max_people - min_people);
				}
			}
		}
	}

	return ret;
}

int main() {
	cin >> N;

	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			cin >> map[row][col];

	cout << solve() << endl;

	return 0;
}