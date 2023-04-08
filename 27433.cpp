#include <iostream>
using namespace std;

typedef unsigned long long ll;

int main() {
	ll dp[21];

	// base case
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= 20; i++)
		dp[i] = i * dp[i - 1];

	int N;
	cin >> N;

	cout << dp[N] << endl;

	return 0;
}