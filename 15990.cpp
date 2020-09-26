#include <iostream>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 9;
const int MAXN = 100000;

ll dp[MAXN + 1][4];

void solve() {
	// 가장 작은 해 셋팅
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int n = 4; n <= MAXN; n++) {
		if (n - 1 >= 0)
			dp[n][1] = (dp[n - 1][2] + dp[n - 1][3]) % mod;

		if(n - 2 >= 0)
			dp[n][2] = (dp[n - 2][1] + dp[n - 2][3]) % mod;

		if(n - 3 >= 0) 
			dp[n][3] = (dp[n - 3][1] + dp[n - 3][2]) % mod;
	}
}


int main() {
	int T;
	cin >> T;

	solve();

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		cout << (dp[n][1] + dp[n][2] + dp[n][3])%mod << '\n';
	}

	return 0;
}