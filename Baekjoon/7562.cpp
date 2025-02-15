#include <iostream>
#include <queue>

using namespace std;

bool check[300][300];

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// ���� ��ǥ, ��ǥ ��ǥ, ü���� ������
int BFS(pair<int, int> start, pair<int, int> target, int l) {
	// �迭 �ʱ�ȭ
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
			check[i][j] = false;

	// first : ��ǥ, second : Ƚ��
	queue<pair<pair<int, int>, int>> q;

	// ù ���� ��ǥ �ֱ�!
	q.push(make_pair(start, 0));

	check[start.first][start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curCnt = q.front().second;

		q.pop();

		// ��ǥ ������ �����ߴٸ� Ƚ�� ��ȯ�ϸ� ����
		if (x == target.first && y == target.second)
			return curCnt;

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			// ü���� ���� ���� �ִٸ�!
			if (0 <= nx && nx < l && 0 <= ny && ny < l) {
				if (check[nx][ny] == false)
				{
					q.push(make_pair(make_pair(nx, ny), curCnt + 1));
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int l, sX, sY, tX, tY;
		cin >> l >> sX >> sY >> tX >> tY;

		cout << BFS(make_pair(sX, sY), make_pair(tX, tY), l) << endl;
	}

	return 0;
}