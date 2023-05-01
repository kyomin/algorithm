#include <iostream>
using namespace std;

int N;
int map[33][33];
long dp[3][33][33];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)		
			cin >> map[i][j];
		
	for (int col = 2; col <= N; col++) {
		if (map[1][col] == 1)
			break;
		else
			dp[0][1][col] = 1;
	}

	for (int r = 2; r <= N; r++) {
		for (int c = 2; c <= N; c++) {
			if (map[r][c] == 1)
				continue;

			dp[0][r][c] = dp[0][r][c - 1] + dp[2][r][c - 1];
			dp[1][r][c] = dp[1][r - 1][c] + dp[2][r - 1][c];

			if (map[r - 1][c] != 1 && map[r][c - 1] != 1)
				dp[2][r][c] = dp[0][r - 1][c - 1] + dp[1][r - 1][c - 1] + dp[2][r - 1][c - 1];
		}
	}

	cout << dp[0][N][N] + dp[1][N][N] + dp[2][N][N];

	return 0;
}