#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int time[501];
int pre[501] = { 0, };
vector<int> suc[501];
int result[501] = { 0, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		vector<int> temp;

		// temp의 사이즈는 2 아니면 1이다.
		while (true) {
			int n;
			cin >> n;

			if (n == -1)
				break;

			temp.push_back(n);
		}

		if (temp.size() == 1)
			time[i] = temp[0];
		else {
			for (int j = 1; j < temp.size(); j++) {
				int v = i;
				int u = temp[j];

				suc[u].push_back(v);
				pre[v]++;
			}

			time[i] = temp[0];
		}
	}

	queue<int> Q;

	// 선행자가 하나도 없는 노드들을 큐에 우선 담는다.
	for (int i = 1; i <= N; i++)
		if (pre[i] == 0)
			Q.push(i);

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		// 모든 후행자 건물의 최소 건설 시간을 갱신
		for (auto next : suc[u]) {
			result[next] = max(result[next],
				result[u] + time[u]
			);

			pre[next]--;

			if (pre[next] == 0)
				Q.push(next);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << result[i] + time[i] << '\n';

	return 0;
}