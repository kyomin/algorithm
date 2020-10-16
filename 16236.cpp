#include <iostream>
#include <queue>

using namespace std;

const int INF = 987654321;

const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

struct Point {
	int r;
	int c;
	int d;	// �� �̵��� �Ÿ�
};

int map[20][20];
int N;

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

int solve(int r, int c) {
	int ret = 0;
	int size = 2;	// �ʱ� ũ��� 2
	int cnt = 2;	// �� Ŀ���� ���� �Ծ�� �� ����� ��
	Point minPt = { r, c, 0 };	// �̵��� ��� ��ġ! ���ǿ� ���� ��� ������ ������.

	do {
		bool visited[20][20] = { false };
		queue<Point> q;
		visited[minPt.r][minPt.c] = true;
		q.push({ minPt.r, minPt.c, 0 });
		minPt.d = INF;

		// BFS Ž��
		while (!q.empty()) {
			Point curr = q.front();
			q.pop();

			/* Ž���� �� ������ �� �ִ��� ���� üũ */

			// minPt�� �� ������ �ʿ䰡 ����.
			if (curr.d > minPt.d) continue;

			// ũ�Ⱑ ū ������ ���� �� ����
			if (map[curr.r][curr.c] > size) continue;

			// ���� �� �ִ� ����⸦ ã�Ҵ�
			if (map[curr.r][curr.c] != 0 && map[curr.r][curr.c] < size) {
				if (curr.d < minPt.d)
					minPt = curr;	// ��� ��ġ ����
				else if (curr.d == minPt.d) {
					// �Ÿ��� ���ٸ� �켱������ ���� �ִ� ����⸦ �Դ´�
					if (curr.r < minPt.r)
						minPt = curr;
					// ���� ������� ���ʿ� �ִ� ����� �Ա�
					else if (curr.r == minPt.r && curr.c < minPt.c)
						minPt = curr;
				}

				// �� Ž���� ������ ����. �� ��ġ���� �ٽ� �����Ѵ�.
				continue;
			}

			for (int k = 0; k < 4; k++) {
				int nr = curr.r + dr[k];
				int nc = curr.c + dc[k];

				if (!isInside(nr, nc)) continue;
				if (visited[nr][nc]) continue;

				visited[nr][nc] = true;
				q.push({ nr, nc, curr.d + 1 });
			}
		} 

		// ���ǿ� ���� ���� �� �ִ� ����⸦ ã�� ���
		if (minPt.d != INF) {
			ret += minPt.d;
			--cnt;

			if (cnt == 0) {
				size += 1;
				cnt = size;
			}

			map[minPt.r][minPt.c] = 0;	// ���� ����� �����ֱ�
		}
	} while (minPt.d != INF);

	return ret;
}

int main() {
	int init_r, init_c;		// �ʱ� �Է� ���� ��� ��ġ
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				init_r = i;
				init_c = j;
				map[i][j] = 0;
			}
		}
	}

	cout << solve(init_r, init_c) << '\n';

	return 0;
}