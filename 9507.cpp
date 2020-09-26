#include <iostream>

using namespace std;

typedef unsigned long long ll;

ll dp[68];

void koong() {
	// 자명한 해는 먼저 등록
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	// 채워 나가자
	for (int n = 4; n <= 67; n++) 
		dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3] + dp[n - 4];
}

int main() {
	koong();

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		cout << dp[n] << '\n';
	}

	return 0;
}