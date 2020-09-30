#include <iostream>
#include <algorithm>

using namespace std;

int score[1001];
int dp[1001];
int N;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	for (int n = 1; n <= N; n++) {
		int maxScore = 0;
		int minScore = 10000;

		cin >> score[n];

		for (int i = n; i > 0; i--) {
			maxScore = max(maxScore, score[i]);
			minScore = min(minScore, score[i]);

			dp[n] = max(dp[n], maxScore - minScore + dp[i - 1]);
		}
	}

	cout << dp[N] << endl;

	return 0;
}