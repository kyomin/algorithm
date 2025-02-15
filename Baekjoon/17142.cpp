#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int dr[] = { 1, -1, 0, 0 };
const int dc[] = { 0, 0, 1, -1 };

struct Point {
	int r, c, d;
};

int N, M;
int map[50][50];
Point virus[10];
int virus_cnt;

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

int countbits(int n) {
	int cnt = 0;

	while (n) {
		// �� �����ʿ� �ִ� ��Ʈ�� �Ǵ��Ѵ�.
		if (n & 1) cnt++;

		// ������ ����Ʈ�� 1��ŭ �ϰ� �Ǹ� �� ������ ��Ʈ�� ������ ������.
		n = n >> 1;	
	}

	return cnt;
}

int solve() {
	int ret = INF;

	// virus_cnt ���� ���̷��� �߿��� M���� �����Ѵ�.
	// ��Ʈ�����ڸ� ���� �κ������� ���س�����.
	for (int subset = 0; subset < (1 << virus_cnt); subset++) {
		// virus_cnt�� ���� ��� �κ����տ� ���ؼ� M��ŭ ��Ʈ�� 1�� ���� �͵鸸 ã�Ƴ��� �Ѵ�.
		if (countbits(subset) == M) {
			bool visited[50][50] = { false };
			int dist = 0;
			queue<Point> q;

			// M��ŭ ������ ���̷����� ť�� ��´�.
			for (int i = 0; i < virus_cnt; i++) {
				if (subset & (1 << i)) {
					visited[virus[i].r][virus[i].c] = true;
					q.push(virus[i]);
				}
			}

			// BFS Ž�� ����!
			while (!q.empty()) {
				Point cur = q.front();
				q.pop();

				if (map[cur.r][cur.c] != 2)
					dist = max(dist, cur.d);

				// �����¿� ����
				for (int k = 0; k < 4; k++) {
					int nr = cur.r + dr[k];
					int nc = cur.c + dc[k];

					// ������ ��� ���
					if (!isInside(nr, nc))
						continue;

					// �̹� �湮�� ���
					if (visited[nr][nc])
						continue;

					// ���� ������ �ϴ� ��ġ�� ���̶��
					if (map[nr][nc] == 1)
						continue;

					visited[nr][nc] = true;
					q.push({ nr, nc, cur.d + 1 });
				}
			}

			// ��ĭ�� �� ä���� ���ߴ��� üũ
			bool is_full = true;
			for (int r = 0; r < N; r++)
				for (int c = 0; c < N; c++)
					if (map[r][c] == 0 && visited[r][c] == false)
						is_full = false;

			if (is_full)
				ret = min(ret, dist);
		}
	}

	if (ret == INF)
		return -1;
	
	return ret;
}

int main() {
	cin >> N >> M;

	virus_cnt = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];

			// ���̷����� ���
			if (map[r][c] == 2) {
				virus[virus_cnt++] = { r, c };
			}
		}
	}

	cout << solve() << endl;

	return 0;
}