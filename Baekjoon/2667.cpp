#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int d[25][25];	// ���� ��ȣ ���Կ� ���
int a[25][25];	// ���� ��ġ ���Կ� ���

vector<int> v;	// �� ������ ������ ��� ���� ����

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n;

// ���� ��(x, y) , ���� ��ȣ cnt
void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	// �켱 �ش� ���� ��ǥ�� ������ȣ ���̱�.
	d[x][y] = cnt;

	// �켱 �ϳ��� ���������� ī��Ʈ�� 1���� ����
	int count = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				// ������ �����ϴ°�? => ��, ���� ������ �����ϴ°�?
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
					count += 1;	// �ش� ������ ī��Ʈ ����
				}
			}
		}
	}

	v.push_back(count);
}

int main() {
	int cnt = 0;
	cin >> n;

	// �迭 d �ʱ�ȭ
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25; j++)
			d[i][j] = 0;

	// �迭 a �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < n; j++)
			a[i][j] = (int)(str[j] - '0');
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			// ���� �湮���� �ʾҴٸ�
			if (a[i][j] == 1 && d[i][j] == 0)
				bfs(i, j, ++cnt);

	sort(v.begin(), v.end());

	// ������ ���� ��ȣ(�� ������ ����) ���!
	cout << cnt << '\n';

	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i] << '\n';

	return 0;
}