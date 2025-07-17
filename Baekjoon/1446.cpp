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

	// 초기화: 지름길을 적용하지 않았을 때의 운전 거리
	for (int i = 0; i <= D; i++)
		dp[i] = i;

	// 현재 위치에서 갖고 있는 값보다 직전에서 한 칸 1 써서 온게 더 작으면 업데이트
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