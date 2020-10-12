#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	if (N == 1) {
		cout << 3 << '\n';
		return 0;
	}

	int **DP = new int*[N + 1];

	for (int i = 1; i <= N; i++)
		DP[i] = new int[3];

	DP[1][0] = 1;
	DP[1][1] = 1;
	DP[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % 9901;
		DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % 9901;
		DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % 9901;
	}

	int ans = (DP[N][0] + DP[N][1] + DP[N][2]) % 9901;

	cout << ans << '\n';

	return 0;
}