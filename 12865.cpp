#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, K, ans;

// first : weight, second : value
pair<int, int> things[101];

int dp[100001];

void solution(int curr) {
	// �־��� ��ǰ�� �� Ž�������� ����!
	if (curr == N)
		return;

	int W = things[curr].first;
	int V = things[curr].second;

	for (int i = 0; i < K; i++) {
		// �Ѱ� ���Ը� ���� �ʴ´ٸ�
		if (i + W <= K) {
			if (dp[i] != -1 && dp[i + W] < dp[i] + V) {
				dp[i + W] = dp[i] + V;
			}
		}
		else  // �Ѱ� ���Ը� �Ѵ� ���� �������� �� �Ѿ�� �ȴ�.
			break;
	}

	solution(curr + 1);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> things[i].first >> things[i].second;

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;

	solution(0);

	for (int i = 0; i <= K; i++)
		ans = max(ans, dp[i]);

	cout << ans << '\n';

	return 0;
}