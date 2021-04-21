#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;
const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, 1, -1 };

struct Shark {
	// s: 속력, d: 이동 방향, z: 크기
	int s, d, z;	
};

// R, C: 맵의 크기, M: 맵 안의 상어 수
int R, C, M;
Shark map[MAX][MAX];

int solve() {
	int sum = 0;
	Shark backup[MAX][MAX];

	// 낚시왕이 열을 따라 이동함
	for (int c = 0; c < C; c++) {
		// 현재 열의 위치 아래(행)에 상어가 있는지 확인한다.
		for (int r = 0; r < R; r++) {
			// 가장 가까운 상어를 잡고, 지도에서 지워준다.
			if (map[r][c].z > 0) {
				sum += map[r][c].z;
				map[r][c].z = 0;
				break;
			}
		}

		memcpy(backup, map, sizeof(map));	// map to backup
		memset(map, 0, sizeof(map));

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				// 현재 상어의 위치는 backup 배열에 있다.
				Shark& cur = backup[r][c];
				if (cur.z > 0) {
					int nr = r + (cur.s*dr[cur.d]);
					int nc = c + (cur.s*dc[cur.d]);

					// 위로 이동하며 격자를 벗어난 경우
					if (nr < 0) {
						nr = -nr;
						cur.d = 1;
					}

					// 아래 격자를 벗어난 경우 => 여러번 튕기는 경우를 다 처리할 수 있다.
					if (nr > R - 1) {
						int q = nr / (R - 1);
						int r = nr % (R - 1);

						if (q % 2 == 0) {
							nr = r;
						}
						else {
							nr = R - 1 - r;
							cur.d = 0;
						}
					}

					// 열에 대한 것도 행과 같은 로직으로 처리한다.
					if (nc < 0) {
						nc = -nc;
						cur.d = 2;
					}

					if (nc > C - 1) {
						int q = nc / (C - 1);
						int r = nc % (C - 1);

						if (q % 2 == 0) {
							nc = r;
						}
						else {
							nc = C - 1 - r;
							cur.d = 3;
						}
					}

					// 현 위치에 있는 상어 중 가장 큰 상어만 남겨야 한다.
					if (map[nr][nc].z < cur.z) {
						map[nr][nc] = cur;
					}
				}
			}
		}
	}

	return sum;
}

int main() {
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		// zero base의 인덱스를 맞추기 위함
		--r;
		--c;
		--d;

		// 맵에 상어의 정보 저장
		map[r][c] = { s, d, z };
	}

	cout << solve() << endl;

	return 0;
}