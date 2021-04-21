#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;
const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, 1, -1 };

struct Shark {
	// s: �ӷ�, d: �̵� ����, z: ũ��
	int s, d, z;	
};

// R, C: ���� ũ��, M: �� ���� ��� ��
int R, C, M;
Shark map[MAX][MAX];

int solve() {
	int sum = 0;
	Shark backup[MAX][MAX];

	// ���ÿ��� ���� ���� �̵���
	for (int c = 0; c < C; c++) {
		// ���� ���� ��ġ �Ʒ�(��)�� �� �ִ��� Ȯ���Ѵ�.
		for (int r = 0; r < R; r++) {
			// ���� ����� �� ���, �������� �����ش�.
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
				// ���� ����� ��ġ�� backup �迭�� �ִ�.
				Shark& cur = backup[r][c];
				if (cur.z > 0) {
					int nr = r + (cur.s*dr[cur.d]);
					int nc = c + (cur.s*dc[cur.d]);

					// ���� �̵��ϸ� ���ڸ� ��� ���
					if (nr < 0) {
						nr = -nr;
						cur.d = 1;
					}

					// �Ʒ� ���ڸ� ��� ��� => ������ ƨ��� ��츦 �� ó���� �� �ִ�.
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

					// ���� ���� �͵� ��� ���� �������� ó���Ѵ�.
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

					// �� ��ġ�� �ִ� ��� �� ���� ū �� ���ܾ� �Ѵ�.
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

		// zero base�� �ε����� ���߱� ����
		--r;
		--c;
		--d;

		// �ʿ� ����� ���� ����
		map[r][c] = { s, d, z };
	}

	cout << solve() << endl;

	return 0;
}