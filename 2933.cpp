#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char a[100][100];
bool c[100][100];
int n, m;

// �̳׶� �׷��� ��ǥ�� ��´�.
vector<pair<int, int>> group;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	// ��ĭ�̹Ƿ� Ž���� �� �����ϸ� �� �ȴ�.
	if (a[x][y] == '.')
		return;
	if (c[x][y])	// �۾��� �̷��� ���� �� �湮 x
		return;

	// �湮�ߴٰ� üũ!
	c[x][y] = true;

	// ���� �̳׶� �׷��� ��ǥ�� �������� �״´�.
	group.push_back(make_pair(x, y));

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < n && 0 <= ny && ny < m)
			dfs(nx, ny);
	}
}

void simulate() {
	memset(c, false, sizeof(c));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// Ž�� ����� �ƴϴ�
			if (a[i][j] == '.')
				continue;
			if (c[i][j])
				continue;

			group.clear();
			// Ž���� ����
			dfs(i, j);

			/*
				Ž���� �� ���� ����
				�׷��� �������� ���̴�.
			*/
			vector<int> low(m, -1);

			for (auto &p : group) {
				// �� ���� ���� ���� ���� �κ��� �� ����
				low[p.second] = max(low[p.second], p.first);

				// �̳׶� ������ �̵���ų ���̹Ƿ� ��ĭ �����
				a[p.first][p.second] = '.';
			}

			/*
				�ش� Ŭ�����Ͱ� �������� ���� ������ �´�� �Ÿ�
				Ŭ�������� �� �κ��̶� �����ϸ� ����ȴ�.
			*/
			int lowest = n;

			for (int i, j = 0; j < m; j++) {
				// Ŭ�����Ϳ� ���Ե� ���� �ƴϸ� �۾� x
				if (low[j] == -1)
					continue;

				// ���𰡿� ���� ������ ��� ������Ų��.
				for (i = low[j]; i < n&&a[i][j] == '.'; i++);

				// for���� ���� ������ ���� �����߰ų�, ���𰡿� ��Ҵ� �Ҹ��̹Ƿ�
				// lowest ����
				lowest = min(lowest, i - 1 - low[j]);
			}

			// �̳׶� Ŭ�����͸� ��ȸ�Ѵ�.
			for (auto &p : group) {
				// �̵��� ��Ų��.
				p.first += lowest;

				a[p.first][p.second] = 'x';
				c[p.first][p.second] = true;
			}

		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
		
	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int height;
		cin >> height;

		height = n - height;

		// ���������� ����� ��
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				if (a[height][j] == 'x') {
					// �̳׶� �� �μ���
					a[height][j] = '.';
					break;
				}
			}
		}
		else {
			for (int j = m - 1; j >= 0; j--) {
				if (a[height][j] == 'x') {
					a[height][j] = '.';
					break;
				}
			}
		}

		simulate();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j];

		cout << '\n';
	}

	cout << '\n';

	return 0;
}