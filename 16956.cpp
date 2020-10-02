#include <iostream>

using namespace std;

int R, C;
char map[500][500];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// ���밡 �������ֱ⸸ �ص� �Ұ����ϹǷ� �װ��� üũ
bool isImpossible() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			// ���� �߰��ϸ� ������ 4���� �����Ѵ�.
			if (map[y][x] == 'S') {
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					// ������ 4���� ���� ���̰�, ������
					if (0 <= nx && nx < C && 0 <= ny && ny < R && map[ny][nx] == 'W') {
						return true;
					}
				}
			}
		}
	}

	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;

	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			cin >> map[y][x];

	if (isImpossible()) {
		cout << 0 << '\n';
	} else {
		cout << 1 << '\n';
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				if (map[y][x] == '.') {
					cout << 'D';
				} else {
					cout << map[y][x];
				}
			}

			cout << '\n';
		}
	}

	return 0;
}