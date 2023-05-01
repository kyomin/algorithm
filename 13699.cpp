#include <iostream>
using namespace std;

int main() {
	unsigned long long dp[36] = { 0, };
	int N;
	cin >> N;

	dp[0] = 1;

	for (int i = 1; i < N + 1; i++)
		for (int j = 0; j < i; j++)
			dp[i] += dp[j] * dp[i - j - 1];

	cout << dp[N];

	return 0;
}