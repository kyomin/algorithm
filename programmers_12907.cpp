#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

unsigned long long dp[100001];

int solution(int n, vector<int> money) {
	int answer = 0;

	// ������ ���� ���� ������ ������ �ϰ� ����
	sort(money.begin(), money.end());

	// ������ ù ����� ���� ��!
	dp[0] = 1;

	int len = money.size();

	for (int i = 0; i < len; i++) {
		int coin = money[i];

		/*
			���� ù �����̶��,
			���� ����� �Ǵ� �͸� ����� �� 1�� �����.
		*/
		if (i == 0) {
			for (int j = coin; j <= n; j++) {
				if (j%coin == 0)
					dp[j] = (dp[j] + 1) % 1000000007;
			}

			continue;
		}

		// ù ������ �ƴ϶�� ������ �����Ѵ�.
		for (int j = coin; j <= n; j++) {
			// ������ ���ε�� ������� �� + ���ο� ������ ������ ���� �� �ִ� ��
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