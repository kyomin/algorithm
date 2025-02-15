#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> dp;
	vector<int> cards;
	int N;
	cin >> N;

	dp.resize(N + 1);
	cards.resize(N + 1);

	dp[0] = 0;
	cards[0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = 0;
		cin >> cards[i];
	}

	dp[1] = cards[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = cards[i];
		for (int j = 1; j <= i; j++)
			dp[i] = min(dp[i], dp[i - j] + cards[j]);
	}

	cout << dp[N] << endl;

	return 0;
}