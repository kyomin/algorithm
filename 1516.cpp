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

		// temp�� ������� 2 �ƴϸ� 1�̴�.
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

	// �����ڰ� �ϳ��� ���� ������ ť�� �켱 ��´�.
	for (int i = 1; i <= N; i++)
		if (pre[i] == 0)
			Q.push(i);

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		// ��� ������ �ǹ��� �ּ� �Ǽ� �ð��� ����
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