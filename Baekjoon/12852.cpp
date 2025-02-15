#include <iostream>

using namespace std;

int N;
int dp[1000001];
int before[1000001];	// 역 추적을 담기 위한 배열

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	before[1] = -1;
	cin >> N;

	for (int n = 2; n <= N; n++) {
		// 1을 빼서 만드는 경우는 항상 존재하고, 
		// 가장 많은 횟수를 차지 하므로
		dp[n] = dp[n - 1] + 1;
		before[n] = n - 1;

		// 2로 나누는 경우로 만들 때
		if (n % 2 == 0 && dp[n] > dp[n / 2] + 1) {
			dp[n] = dp[n / 2] + 1;
			before[n] = n / 2;
		}

		// 3으로 나누는 경우로 만들 때
		if (n % 3 == 0 && dp[n] > dp[n / 3] + 1) {
			dp[n] = dp[n / 3] + 1;
			before[n] = n / 3;
		}
	}

	cout << dp[N] << endl;

	while (N != -1) {
		cout << N << ' ';

		N = before[N];
	}

	return 0;
}