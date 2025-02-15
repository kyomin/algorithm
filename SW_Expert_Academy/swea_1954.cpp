#include <iostream>

using namespace std;

const int MAX = 10;
const int dr[] = { 0, 1, 0, -1 };
const int dc[] = { 1, 0, -1, 0 };

int map[MAX][MAX];
int N;

void init() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			map[r][c] = 0;
}

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		init();
		
		int cur_dir = 0;
		int cur_r = 0;
		int cur_c = 0;
		int cur_num = 1;

		while (true) {
			// �迭�� ���� ���ڸ� ǥ��
			map[cur_r][cur_c] = cur_num;
			cur_num++;

			int next_r = cur_r + dr[cur_dir];
			int next_c = cur_c + dc[cur_dir];
			
			if (!isInside(next_r, next_c)) {	// ���� ������ ��� ����� ������ �ٲ㺻��.
				cur_dir += 1;

				// ���� ����(3) �����̶�� �ٽ� ���� ����(0)���� �ʱ�ȭ
				if (cur_dir == 4)
					cur_dir = 0;

				// ����, ������ �ٲ�µ��� �������� �� �� ���� ����� ���ڸ� �� ä�� ����̴�.
				next_r = cur_r + dr[cur_dir];
				next_c = cur_c + dc[cur_dir];

				if (map[next_r][next_c] != 0)
					break;

				cur_r = next_r;
				cur_c = next_c;
			}
			else if (map[next_r][next_c] != 0) {	// �̹� ǥ�ð� �� ����� ������ �ٲ㺻��.
				cur_dir += 1;

				// ���� ����(3) �����̶�� �ٽ� ���� ����(0)���� �ʱ�ȭ
				if (cur_dir == 4)
					cur_dir = 0;

				// ����, ������ �ٲ�µ��� �������� �� �� ���� ����� ���ڸ� �� ä�� ����̴�.
				next_r = cur_r + dr[cur_dir];
				next_c = cur_c + dc[cur_dir];

				if (map[next_r][next_c] != 0)
					break;

				cur_r = next_r;
				cur_c = next_c;
			}
			else {		// �׳� �������� ���� �Ǵ� ����� ����.
				cur_r = next_r;
				cur_c = next_c;
			}
		}

		cout << '#' << t << '\n';
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N - 1; c++)
				cout << map[r][c] << ' ';

			cout << map[r][N - 1] << '\n';
		}
	}

	return 0;
}