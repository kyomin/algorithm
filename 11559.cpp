#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
	�� ���� �����ϱ� ���� �迭
	flag �迭���� 2�� �͸� ��� temp �迭��
	�ڿ������� ���� �־��ְ� ������ ���� ������
	���� ����
*/
vector<char> temp;

/*
	������ ���θ� ��� ���� �迭
	4�� �̸��̸� false, 4�� �̻��̸� true ����
*/
bool flag[12][6];

/*
	4�� �̻��� �ϳ��� �����,
	replay�� true�� ������ش�.

	Ž���� ���� replay�� true�̸�
	������ Ƚ���� �߰����ְ�,
	false��� ���� ���� �ϳ��� ���� ���̹Ƿ�
	�����Ѵ�.
*/
bool replay;

bool check[12][6];	// �湮 ����
int cnt = 0;	// ���� Ƚ��
string a[12];	// �ѿ��� �ʱ� ����(map ����)

/*
	�� �� �� �� Ž���� �迭
*/
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// ���� ���� �迭 �ʱ�ȭ
void Init() {
	replay = false;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			check[i][j] = false;
			flag[i][j] = false;
		}
	}
}

void BFS(int x, int y, char color) {
	vector<pair<int, int>> v;	// Ž�� ���� ������� ��ǥ�� ��� ���� ����
	queue<pair<int, int>> q;
	int count = 1;

	q.push(make_pair(x, y));
	v.push_back(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < 12 && 0 <= ny && ny < 6) {
				if (a[nx][ny] == color && !check[nx][ny]) {
					q.push(make_pair(nx, ny));
					v.push_back(make_pair(nx, ny));
					check[nx][ny] = true;
					count += 1;
				}
			}
		}
	}

	// Ž���� �� ���� 4�� �̻��� ���� ������ �ִٸ�
	if (count >= 4) {
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;

			flag[x][y] = true;
		}

		replay = true;
	}
}

int main() {
	for (int i = 0; i < 12; i++)
		cin >> a[i];

	while (true) {
		Init();

		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
				if (a[i][j] != '.' && !check[i][j])
					BFS(i, j, a[i][j]);

		// 4�� �̻��̾ ������ ������ �ϳ��� ������
		// ���� Ƚ�� ���� �� �� �ٽ� �׸���
		if (replay) {
			cnt += 1;

			for (int i = 0; i < 6; i++) {
				int count = 0;

				for (int j = 11; j >= 0; j--) {
					// ������ �ʾ� �״�� ���� �ִ� �κ��̶��
					if (!flag[j][i])
						temp.push_back((char)a[j][i]);
					else
						// ������ �κ��̶�� �ش� ���� �� ���� ����
						count += 1;
				}

				// ������ �κ� ������ ä���
				for (int j = 0; j < count; j++)
					temp.push_back('.');

				// �׷��� �ش� ���� ���� �׸��� ���� temp�� ����.
				// a�� �ٽ� �׷�����
				for (int j = 0; j < 12; j++)
					a[j][i] = temp[11 - j];

				// a�� �ش� ���� �ٽ� �׷������� temp Ŭ����!
				temp.clear();
			}
		}
		else
			break;
	}

	cout << cnt << endl;

	return 0;
}