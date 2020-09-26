#include <iostream>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 9;
const int MAXN = 1000000;

// dp[n] : n�� 1, 2, 3�� ������ ��Ÿ���� ����� ��
ll dp[MAXN + 1];

void solve() {
	// ���� ���� �� ����
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