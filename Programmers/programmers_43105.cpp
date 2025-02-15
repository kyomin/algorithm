#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	int len = triangle.size();

	if (len == 1)
		return triangle[0][0];

	int DP[500][500];

	/* 자명한 최소 해 먼저 구하기 */
	DP[0][0] = triangle[0][0];
	DP[1][0] = triangle[0][0] + triangle[1][0];
	DP[1][1] = triangle[0][0] + triangle[1][1];

	for (int i = 2; i < len; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				DP[i][j] = triangle[i][j] + DP[i - 1][j];

			if (j == i)
				DP[i][j] = triangle[i][j] + DP[i - 1][j - 1];

			DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + triangle[i][j];
		}
	}

	for (int i = 0; i < len; i++)
		if (DP[len - 1][i] > answer)
			answer = DP[len - 1][i];

	return answer;
}