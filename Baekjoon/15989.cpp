#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 1000000;

ll dp[MAXN + 1][4];

void solve() {
	// 가장 작은 해 셋팅
	dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int n = 4; n <= MAXN; n++) {
		dp[n][3] = dp[n - 3][1] + dp[n - 3][2] + dp[n - 3][3];
		dp[n][2] = dp[n - 2][1] + dp[n - 2][2];
		dp[n][1] = dp[n - 1][1];
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	solve();

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		cout << (dp[n][1] + dp[n][2] + dp[n][3]) << '\n';
	}

	return 0;
}