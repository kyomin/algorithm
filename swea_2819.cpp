#include <iostream>
#include <set>
#include <string>
#include <queue>

using namespace std;

int board[4][4];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

set<string> s;

void dfs(int y, int x, string str) {
	// 7 �ڸ��� �ϼ��Ǹ�
	if (str.size() == 7) {
		s.insert(str);
		return;
	}

	str += to_string(board[y][x]);

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
			dfs(ny, nx, str);
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		// �� �׽�Ʈ ���̽����� ���Ӱ� ������ �Է�
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> board[i][j];
			}
		}

		// set �����̳� �ʱ�ȭ
		s.clear();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs(j, i, "");
			}
		}

		cout << '#'<<t<<' '<<s.size() << '\n';
	}

	return 0;
}