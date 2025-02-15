#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int RIGHT = 1;
const int LEFT = 2;
const int INF = 987654321;

int N, M, H;
int ladder[30][10];

bool check() {
	for (int i = 0; i < N; i++) {
		int row = 0;
		int col = i;

		do {
			if (ladder[row][col] == LEFT)
				col--;
			else if (ladder[row][col] == RIGHT)
				col++;

			row++;	// ����, ���������� ��������, ��������.
		} while (row != H);

		// ���� �������� ��, ���� ���� ������ �ʴٸ�
		if (i != col)
			return false;
	}

	// ���� �ݺ����� �� ���ƴٸ� ���͸��� �� ���̴�.
	return true;
}

// pos: �� ��ġ, cnt: ������ ����
int solve(int pos, int cnt) {
	// base case : 3���� ������ ���߰ų�, ������ �� ���
	if (cnt == 3 || pos >= (N*H)) {
		if (check())
			return cnt;

		return INF;
	}

	// row = pos/col_cnt
	// col = pos%col_cnt
	int ret = INF;
	int row = pos / N;
	int col = pos % N;

	// ���� ������ ��ġ�� �ƴ� ��쿡�� ���μ��� ���� �� �ִ�.
	if (col != N - 1 && ladder[row][col] == 0 && ladder[row][col+1] == 0) {
		ladder[row][col] = RIGHT;
		ladder[row][col + 1] = LEFT;

		ret = min(ret, solve(pos + 2, cnt + 1));

		// �ٽ� ���� => ���� �� �Ѱɷ� �����ش�.
		ladder[row][col] = 0;
		ladder[row][col + 1] = 0;
	}

	ret = min(ret, solve(pos + 1, cnt));

	return ret;
}

int main() {
	cin >> N >> M >> H;
	memset(ladder, 0, sizeof(ladder));

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		// �ε����� �����ֱ� ����
		ladder[a - 1][b - 1] = RIGHT;
		ladder[a - 1][b] = LEFT;
	}

	int ans = solve(0, 0);
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}