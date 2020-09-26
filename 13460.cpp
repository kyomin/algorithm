#include <iostream>
#include <queue>

using namespace std;

/*
	x : 행
	y : 열
*/
struct bead {
	int rx, ry;		// 빨간 구슬 좌표
	int bx, by;		// 파란 구슬 좌표
	int d;			// 굴리는 과정
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

		// 굴린 횟수가 10을 넘기면
		if (d >= 10) break;

		for (int i = 0; i < 4; i++) {
			int nrx = rx;
			int nry = ry;
			int nbx = bx;
			int nby = by;

			// 한 번의 굴림으로 각각 공이 움직인 횟수
			int rc = 0;
			int bc = 0;

			// 빨간 구슬 움직이기
			move(nrx, nry, rc, dx[i], dy[i]);

			// 파란 구슬 움직이기
			move(nbx, nby, bc, dx[i], dy[i]);

			// 파란 구슬이 구멍에 들어간 경우!
			if (a[nbx][nby] == 'O') continue;

			// 빨간 구슬이 구멍에 들어간 경우!
			if (a[nrx][nry] == 'O') {
				// 해를 찾은 것이다!
				cout << d+1 << '\n';
				return;
			}

			// 구슬은 서로 같은 위치에 놓일 수 없다!
			if (nrx == nbx && nry == nby) {
				// 이동 거리가 더 긴 구슬을 한 칸 이전으로 돌린다!
				if (rc > bc) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			// 굴리는 과정의 결과가 이미 이전에 체크된 것이라면!
			if (check[nrx][nry][nbx][nby]) continue;

			check[nrx][nry][nbx][nby] = true;

			q.push({ nrx, nry, nbx, nby, d + 1 });
		}
	}

	// 탐색을 다 했는데도 해를 못 찾았다면
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