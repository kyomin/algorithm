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
	// 채취할 수 있는 꿀의 최대 양 C를 초과할 경우
	if (sum_honey > C)
		return;

	// 해답은 수시로 갱신
	result = max(result, sum_profit);

	// 해답 갱신 후 벌통의 수 M을 넘었는지 체크해본다.
	if (cnt == M)
		return;

	getScore(r, c + 1, cnt + 1, sum_honey + board[r][c], sum_profit + pow(board[r][c], 2));		// 꿀을 더해주는 경우
	getScore(r, c + 1, cnt + 1, sum_honey, sum_profit);		// 꿀을 더하지 않고 cnt만 증가
}

int solve(int r, int c) {
	for (int i = 0; i < M; i++)
		visited[r][c + i] = true;

	result = 0;
	getScore(r, c, 0, 0, 0);

	// A일꾼은 고정돼 있으므로 result를 그냥 대입해 주면 된다.
	int cost_A = result;
	int cost_B = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			if (visited[i][j])
				continue;

			result = 0;
			getScore(i, j, 0, 0, 0);
			
			// A일꾼을 고정해 놓고 B일꾼이 완전 탐색하는 경우이므로 계속 갱신해 준다.
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