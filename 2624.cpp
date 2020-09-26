#include <iostream>
#include <algorithm>

using namespace std;

int T, K;
pair<int, int> coin[100];		// first : coin ��ġ, second : ����
int dp[10001];		// ������ �ݾ��� ����� ������

// coin ��ġ�� �������� �������� ������ ���̴�.
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

	// ������ ��ġ�� ���� �����ϰ� �����Ѵ�.
	sort(coin, coin + K);

	dp[0] = 1;

	for (int k = 0; k < K; k++) {
		int curCoin = coin[k].first;
		int curCoinNum = coin[k].second;

		// ���� ù �����̶�� ���� ����� �Ǵ� �͸� ����� �� 1�� �����.
		if (k == 0) {
			for (int i = 1; i <= curCoinNum; i++)
				dp[curCoin*i] += 1;

			continue;
		}

		// ù ������ �ƴ϶�� ������ �����Ѵ�.
		int preCoinNum = coin[k - 1].second;	// ���� ���� ����
		int preCoin = coin[k - 1].first;		// ���� ���� ��ġ
		
		int boundary = curCoinNum * curCoin + preCoinNum * preCoin;

		for (int i = curCoin; i <= curCoinNum * curCoin; i++) {
			if (i > 10000)
				break;
			// ������ ���ε�� ������� �� + ���ο� ������ ������ ���� �� �ִ� ��
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