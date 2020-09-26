#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

unsigned long long dp[100001];

int solution(int n, vector<int> money) {
	int answer = 0;

	// 동전의 값은 먼저 오름차 정렬을 하고서 접근
	sort(money.begin(), money.end());

	// 코인의 첫 배수를 위한 것!
	dp[0] = 1;

	int len = money.size();

	for (int i = 0; i < len; i++) {
		int coin = money[i];

		/*
			만일 첫 코인이라면,
			그의 배수가 되는 것만 경우의 수 1로 만든다.
		*/
		if (i == 0) {
			for (int j = coin; j <= n; j++) {
				if (j%coin == 0)
					dp[j] = (dp[j] + 1) % 1000000007;
			}

			continue;
		}

		// 첫 코인이 아니라면 다음을 시행한다.
		for (int j = coin; j <= n; j++) {
			// 기존의 코인들로 만들었던 것 + 새로운 코인이 개입해 만들 수 있는 것
			dp[j] = (dp[j] + dp[j-coin]) % 1000000007;
		}
	}

	answer = dp[n];

	return answer;
}

int main() {
	// Test 1
	cout << solution(5, { 1, 2, 5 }) << endl;

	return 0;
}