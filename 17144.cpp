#include <iostream>
#include <queue>

using namespace std;

const int MAX = 50;
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int map[MAX][MAX];
int copy_map[MAX][MAX];
int R, C, T;

pair<int, int> air_cleaner[2];	// 0: ��, 1: �Ʒ�

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

// ���� �����ΰ�?
bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;
	else
		return false;
}

// 2���� �迭 �Ű� ������ ���� ũ�⸸ ����!
void copyMap(int original[][MAX], int duplicate[][MAX]) {
	for (int row = 0; row < R; row++)
		for (int col = 0; col < C; col++)
			duplicate[row][col] = original[row][col];
}

// ������ Ȯ�� ��Ų��!
void spreadDust() {
	copyMap(map, copy_map);

	for (int row = 0; row < R; row++) {
		for (int col = 0; col < C; col++) {
			// ������� Ȯ��!
			if (map[row][col] != 0 && map[row][col] != -1) {
				int cnt = 0;	// Ȯ��� ������ ����
				int val = map[row][col] / 5;	// Ȯ��Ǵ� ��

				for (int k = 0; k < 4; k++) {
					int nr = row + dr[k];
					int nc = col + dc[k];

					// ���� ���θ� �����
					if (!isInside(nr, nc)) continue;

					// ���� û���Ⱑ �ƴ϶�� Ȯ�� ����
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

// �ٶ����� ������ �о��!
void moveDust() {
	// ���� û������ �� ĭ, �Ʒ� ĭ�� ���� ����Ѵ�.
	int up = 0;
	int down = 1;

	/* 
		�� ĭ 
	*/
	// 1. ���� ����(0, 0)���� �ڱ� ���̱��� �����
	for (int i = air_cleaner[up].first - 1; i > 0; i--)
		map[i][0] = map[i - 1][0];

	// 2. ���� ���� �������� �����
	for (int i = 0; i < C - 1; i++)
		map[0][i] = map[0][i + 1];

	// 3. ���� ������ ���� �����ֱ�
	for (int i = 1; i <= air_cleaner[up].first; i++)
		map[i - 1][C - 1] = map[i][C - 1];

	// 4. ���� û���Ⱑ ��ġ�� ���� ���������� �����
	for (int i = C - 1; i > 1; i--)
		map[air_cleaner[up].first][i] = map[air_cleaner[up].first][i - 1];

	/*
		�Ʒ� ĭ
	*/
	// 1. ���� ���� �� �Ʒ��� �ڱ���� �����
	for (int i = air_cleaner[down].first + 1; i < R - 1; i++)
		map[i][0] = map[i + 1][0];

	// 2. ���� �Ʒ��� �� �������� �����
	for (int i = 0; i < C - 1; i++)
		map[R - 1][i] = map[R - 1][i + 1];

	// 3. ���� ������ �� �Ʒ��� �����
	for (int i = R - 1; i > air_cleaner[down].first; i--)
		map[i][C - 1] = map[i - 1][C - 1];

	// 4. �Ʒ��� ���� û���Ⱑ ��ġ�� ���� ���������� �����
	for (int i = C - 1; i > 1; i--)
		map[air_cleaner[down].first][i] = map[air_cleaner[down].first][i - 1];


	// ���� û����κ��� ���������� ���� ���� ��ȭ�� 0�̴�.
	map[air_cleaner[up].first][1] = 0;
	map[air_cleaner[down].first][1] = 0;
}

// ���������� �����ִ� ������ ���� ����.
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