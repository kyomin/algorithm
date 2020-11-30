#include <iostream>

using namespace std;

unsigned long long dp[117];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	int N;
	cin >> N;

	if (N == 1 || N == 2 || N == 3) {
		cout << 1 << '\n';
		return 0;
	}

	for (int i = 4; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 3];

	cout << dp[N] << '\n';

	return 0;
}