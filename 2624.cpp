#include <iostream>
#include <algorithm>

using namespace std;

int T, K;
pair<int, int> coin[100];		// first : coin 가치, second : 개수
int dp[10001];		// 지폐의 금액을 만드는 가지수

// coin 가치를 기준으로 오름차순 정렬할 것이다.
bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.first < p2.first)
		return true;
	else
		return false;
}

int main() {
	cin >> T >> K;

	for (int k = 0; k < K; k++) {
		int val, num;
		cin >> val >> num;

		coin[k] = make_pair(val, num);
	}

	// 동전의 가치는 먼저 정렬하고서 접근한다.
	sort(coin, coin + K);

	dp[0] = 1;

	for (int k = 0; k < K; k++) {
		int curCoin = coin[k].first;
		int curCoinNum = coin[k].second;

		// 만일 첫 코인이라면 그의 배수가 되는 것만 경우의 수 1로 만든다.
		if (k == 0) {
			for (int i = 1; i <= curCoinNum; i++)
				dp[curCoin*i] += 1;

			continue;
		}

		// 첫 코인이 아니라면 다음을 시행한다.
		int preCoinNum = coin[k - 1].second;	// 이전 코인 개수
		int preCoin = coin[k - 1].first;		// 이전 코인 가치
		
		int boundary = curCoinNum * curCoin + preCoinNum * preCoin;

		for (int i = curCoin; i <= curCoinNum * curCoin; i++) {
			if (i > 10000)
				break;
			// 기존의 코인들로 만들었던 것 + 새로운 코인이 개입해 만들 수 있는 것
			dp[i] += dp[i - curCoin];
		}

		for (int i = curCoinNum * curCoin + 1; i <= boundary * curCoin; i++) {
			if (i > 10000)
				break;
			
			dp[i] += 1;
		}
	}

	cout << dp[T] << '\n';

	return 0;
}