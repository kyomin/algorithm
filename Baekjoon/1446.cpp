#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ShortCut {
	int start;
	int end;
	int dist;
};

int main() {
	int N, D;
	cin >> N >> D;

	vector<int> dp(D + 1);
	vector<ShortCut> shortCutList;

	for (int i = 0; i < N; i++) {
		int start, end, dist;
		cin >> start >> end >> dist;

		shortCutList.push_back({ start, end, dist });
	}

	// �ʱ�ȭ: �������� �������� �ʾ��� ���� ���� �Ÿ�
	for (int i = 0; i <= D; i++)
		dp[i] = i;

	// ���� ��ġ���� ���� �ִ� ������ �������� �� ĭ 1 �Ἥ �°� �� ������ ������Ʈ
	for (int i = 0; i <= D; i++) {
		if (i > 0) {
			dp[i] = min(dp[i], dp[i - 1] + 1);
		}

		for (ShortCut now : shortCutList) {
			if (i == now.start && now.end <= D) {
				dp[now.end] = min(dp[now.end], dp[now.start] + now.dist);
			}
		}
	}

	cout << dp[D] << endl;

	return 0;
}