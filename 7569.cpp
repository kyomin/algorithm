#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct position {
	int row, col, height;
};

int tomato[100][100][100];
int dist[100][100][100];
bool check[100][100][100];

int R, C, H;

const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };
const int dh[2] = { 1, -1 };

bool isInPlane(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;
	else
		return false;
}

bool isInHeight(int h) {
	if (0 <= h && h < H)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> C >> R >> H;

	bool isZero = true;
	queue<position> q;

	for (int height = 0; height < H; height++) {
		for (int row = 0; row < R; row++) {
			for (int col = 0; col < C; col++) {
				cin >> tomato[row][col][height];

				// ó���� �丶�� ��ġ���� ť�� ��´�.
				if (tomato[row][col][height] == 1) {
					q.push({ row, col, height });

					// �湮 üũ!
					check[row][col][height] = true;
				}

				// �� ���� �丶�䰡 �Էµƴٸ� �� ���� �丶�䰡 �����ϹǷ�
				if (tomato[row][col][height] == 0)
					isZero = false;
			}
		}
	}

	// map�� �� �Է��ߴµ�, �� ���� �丶�䰡 ���ٸ�
	if (isZero) {
		cout << 0 << '\n';
		return 0;
	}

	// BFS ���� !!
	while (!q.empty()) {
		int row = q.front().row;
		int col = q.front().col;
		int height = q.front().height;

		q.pop();

		// 1. ��� �� �� �� �� Ž�� !!
		for (int k = 0; k < 4; k++) {
			int nr = row + dr[k];
			int nc = col + dc[k];

			// ��� ������ ����� ���
			if (!isInPlane(nr, nc))
				continue;

			// �̹� �湮�� ���
			if (check[nr][nc][height])
				continue;

			// �� ���� �丶�䰡 �ƴ϶��
			if (tomato[nr][nc][height] != 0)
				continue;

			// ���� ���� ������ �� ���������
			q.push({ nr, nc, height });

			dist[nr][nc][height] = dist[row][col][height] + 1;

			check[nr][nc][height] = true;
		}

		// 2. ���� �� �Ʒ� Ž�� !!
		for (int k = 0; k < 2; k++) {
			int nh = height + dh[k];

			// ���� ������ ����� ���
			if (!isInHeight(nh))
				continue;

			// �̹� �湮�� ���
			if (check[row][col][nh])
				continue;

			// �� ���� �丶�䰡 �ƴ϶��
			if (tomato[row][col][nh] != 0)
				continue;

			// ���� ���� ������ �� ���������
			q.push({ row, col, nh });

			dist[row][col][nh] = dist[row][col][height] + 1;

			check[row][col][nh] = true;
		}
	}

	int result = 0;

	for (int height = 0; height < H; height++) {
		for (int row = 0; row < R; row++) {
			for (int col = 0; col < C; col++) {
				// �� ���� �丶���ε�, �湮�� �� �ߴٸ� �� ������ ���� ���̴�
				if (tomato[row][col][height] == 0 && !check[row][col][height]) {
					cout << -1 << '\n';
					return 0;
				}

				result = max(dist[row][col][height], result);
			}
		}
	}

	cout << result << '\n';

	return 0;
}