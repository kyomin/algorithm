#include <iostream>
#include <queue>

using namespace std;

/*
	x : ��
	y : ��
*/
struct bead {
	int rx, ry;		// ���� ���� ��ǥ
	int bx, by;		// �Ķ� ���� ��ǥ
	int d;			// ������ ����
};

int R, C;
char a[10][10];
bool check[10][10][10][10];
queue<bead> q;

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

bool isInside(int x, int y) {
	if (0 <= x && x < R && 0 <= y && y < C)
		return true;
	else
		return false;
}

void move(int &x, int &y, int &cnt, int dx, int dy) {
	while (isInside(x + dx, y + dy) && a[x + dx][y + dy] != '#' && a[x][y] != 'O') {
		x += dx;
		y += dy;
		cnt += 1;
	}
}

void bfs() {
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int d = q.front().d;

		q.pop();

		// ���� Ƚ���� 10�� �ѱ��
		if (d >= 10) break;

		for (int i = 0; i < 4; i++) {
			int nrx = rx;
			int nry = ry;
			int nbx = bx;
			int nby = by;

			// �� ���� �������� ���� ���� ������ Ƚ��
			int rc = 0;
			int bc = 0;

			// ���� ���� �����̱�
			move(nrx, nry, rc, dx[i], dy[i]);

			// �Ķ� ���� �����̱�
			move(nbx, nby, bc, dx[i], dy[i]);

			// �Ķ� ������ ���ۿ� �� ���!
			if (a[nbx][nby] == 'O') continue;

			// ���� ������ ���ۿ� �� ���!
			if (a[nrx][nry] == 'O') {
				// �ظ� ã�� ���̴�!
				cout << d+1 << '\n';
				return;
			}

			// ������ ���� ���� ��ġ�� ���� �� ����!
			if (nrx == nbx && nry == nby) {
				// �̵� �Ÿ��� �� �� ������ �� ĭ �������� ������!
				if (rc > bc) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			// ������ ������ ����� �̹� ������ üũ�� ���̶��!
			if (check[nrx][nry][nbx][nby]) continue;

			check[nrx][nry][nbx][nby] = true;

			q.push({ nrx, nry, nbx, nby, d + 1 });
		}
	}

	// Ž���� �� �ߴµ��� �ظ� �� ã�Ҵٸ�
	cout << -1 << '\n';
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int rx = 0, ry = 0, bx = 0, by = 0;
	cin >> R >> C;

	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			cin >> a[x][y];

			if (a[x][y] == 'R') {
				rx = x;
				ry = y;
				continue;
			}

			if (a[x][y] == 'B') {
				bx = x;
				by = y;
				continue;
			}
		}
	}

	q.push({ rx, ry, bx, by, 0 });
	check[rx][ry][bx][by] = true;

	bfs();

	return 0;
}