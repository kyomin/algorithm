  #include <iostream>
#include <cstring>

using namespace std;

int map[101][101];
unsigned long long dp[101][101];

int N;

unsigned long long dfs(int y, int x) {
	// 끝에 도달한 경우라면
	if (y == N - 1 && x == N - 1)
		return 1;

	// 아직 방문하지 않은 곳이라면
	if (dp[y][x] == -1) {
		dp[y][x] = 0;

		int nextRight = x + map[y][x];		// 오른쪽으로 가는 경우 
		int nextBottom = y + map[y][x];		// 아래로 가는 경우

		// 지도 범위 내라면
		if (nextRight < N)
			dp[y][x] += dfs(y, nextRight);

		if (nextBottom < N)
			dp[y][x] += dfs(nextBottom, x);
	}

	return dp[y][x];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	cout << dfs(0, 0) << '\n';

	return 0;
}