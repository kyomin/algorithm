#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> suc[1000];		// ���� ����Ʈ
int pre[1000] = { 0, };		// �������� ����(indegree)
int N, M;
int cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		vector<int> temp;

		for (int j = 0; j < num; j++) {
			int u;
			cin >> u;
			temp.push_back(u);
		}

		for (int j = 0; j < num - 1; j++) {
			int u = temp[j];
			int v = temp[j + 1];

			suc[u - 1].push_back(v - 1);
			pre[v - 1]++;
		}
	}

	queue<int> Q;
	vector<int> result;
	cnt = 0;

	for (int i = 0; i < N; i++)
		if (pre[i] == 0)
			Q.push(i);

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		cnt++;	// �湮�� ������ ī��Ʈ ����

		result.push_back(u);

		for (auto next : suc[u]) {
			pre[next]--;

			if (pre[next] == 0)
				Q.push(next);
		}
	}

	// ��� ���� �湮�� ��������!
	if (cnt != N) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < N; i++)
		cout << result[i] + 1 << '\n';

	return 0;
}