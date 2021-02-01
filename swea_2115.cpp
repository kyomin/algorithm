#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 10;
int N, M, C, result;
int board[MAX][MAX];
bool visited[MAX][MAX];

void getScore(int r, int c, int cnt, int sum_honey, int sum_profit) {
	// ä���� �� �ִ� ���� �ִ� �� C�� �ʰ��� ���
	if (sum_honey > C)
		return;

	// �ش��� ���÷� ����
	result = max(result, sum_profit);

	// �ش� ���� �� ������ �� M�� �Ѿ����� üũ�غ���.
	if (cnt == M)
		return;

	getScore(r, c + 1, cnt + 1, sum_honey + board[r][c], sum_profit + pow(board[r][c], 2));		// ���� �����ִ� ���
	getScore(r, c + 1, cnt + 1, sum_honey, sum_profit);		// ���� ������ �ʰ� cnt�� ����
}

int solve(int r, int c) {
	for (int i = 0; i < M; i++)
		visited[r][c + i] = true;

	result = 0;
	getScore(r, c, 0, 0, 0);

	// A�ϲ��� ������ �����Ƿ� result�� �׳� ������ �ָ� �ȴ�.
	int cost_A = result;
	int cost_B = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			if (visited[i][j])
				continue;

			result = 0;
			getScore(i, j, 0, 0, 0);
			
			// A�ϲ��� ������ ���� B�ϲ��� ���� Ž���ϴ� ����̹Ƿ� ��� ������ �ش�.
			cost_B = max(cost_B, result);
		}
	}
	
	return cost_A + cost_B;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		memset(visited, false, sizeof(visited));

		cin >> N >> M >> C;

		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				cin >> board[r][c];

		int ans = 0;

		for (int r = 0; r < N; r++)
			for (int c = 0; c < N - M + 1; c++)
				ans = max(ans, solve(r, c));

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}