#include <vector>
#include <algorithm>

using namespace std;

int dp[100000][4];

int solution(vector<vector<int> > land) {
	int answer = 0;
	int R, C;
	R = land.size();
	C = 4;
	
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if(r == 0) {
				dp[r][c] = land[r][c];
				continue;
			}

			int n = 0;

			for (int k = 0; k < C; k++) {
				if (k == c) continue;
				
				n = max(n, dp[r - 1][k]);
			}

			dp[r][c] = n + land[r][c];
		}
	}

	for (int c = 0; c < C; c++)
		answer = max(answer, dp[R - 1][c]);

	return answer;
}