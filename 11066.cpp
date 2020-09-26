#include <iostream>
#include <cstring>
#include <limits>
#include <algorithm>

using namespace std;

int T, K;
const int INF = numeric_limits<int>::max();

/*
	dp[i][j] : i부터 j까지 파일을 합치는 데 드는 최소 비용을 기록한다.
	2개의 파일을 합치는 규칙이므로 두 부분으로 나뉨을 명시하자.
*/
int dp[501][501];
int sum[501];
int file[501];

int main() {
	cin >> T;

	for (int t = 0; t < T; t++) {
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		memset(file, 0, sizeof(file));

		cin >> K;

		for (int k = 1; k <= K; k++) {
			cin >> file[k];

			sum[k] = sum[k - 1] + file[k];
		}

		for (int gap = 1; gap < K; gap++) {
			for (int start = 1; start + gap <= K; start++) {
				int end = start + gap;
				dp[start][end] = INF;

				for (int mid = start; mid < end; mid++) {
					dp[start][end] = min(dp[start][end],
						dp[start][mid] + dp[mid + 1][end]
						+ sum[end] - sum[start - 1]);
				}
			}
		}

		cout << dp[1][K] << '\n';
	}

	return 0;
}