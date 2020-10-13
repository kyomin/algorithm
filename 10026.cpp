#include <iostream>
#include <queue>
#include <string>

using namespace std;

string a[100];
bool check[100][100];	// �湮 ǥ�ÿ�
int N;	// �׸����� ũ��

// �����¿� Ž�� ����
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// ��, ��, Ž�� ���� ���� ��
void BFS(int x, int y, char color) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	check[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (a[nx][ny] == color && check[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> a[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			check[i][j] = false;

	// �Ϲ� ����� ���� ������ ����
	int cnt1 = 0;

	// ���ϻ����� ���� ������ ����
	int cnt2 = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false) {
				BFS(i, j, a[i][j]);
				cnt1 += 1;
			}
		}
	}

	/* �Ϲݻ���� ���� ����� �������� ���ϻ��� ����� �����Ѵ�. */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// ��� -> ����
			if (a[i][j] == 'G')
				a[i][j] = 'R';

			// check �迭�� �Բ� �ʱ�ȭ
			check[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false) {
				BFS(i, j, a[i][j]);
				cnt2 += 1;
			}
		}
	}

	cout << cnt1 << ' ' << cnt2 << endl;

	return 0;
}