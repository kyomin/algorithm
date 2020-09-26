#include <iostream>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 9;
const int MAXN = 1000000;

// dp[n] : n을 1, 2, 3의 합으로 나타내는 방법의 수
ll dp[MAXN + 1];

void solve() {
	// 가장 작은 해 셋팅
	dp[1] = 1;
	dp[2] = 2; 
	dp[3] = 4;

	for (int n = 4; n <= MAXN; n++) {
		dp[n] = (dp[n - 1] + dp[n - 2] + dp[n - 3])%mod;
	}
}

int main() {
	int T;
	cin >> T;

	solve();

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		cout << dp[n] % mod << '\n';
	}

	return 0;
}