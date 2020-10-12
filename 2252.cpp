#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	int pre[32000] = { 0, };	// �������� ����
	vector<int> suc[32000];	// ������ ��� ����Ʈ
	vector<int> start_node;	// ���� ������ ��´�.

	cin >> N >> K;

	// ���� ���� �Է�
	for (int i = 0; i < K; i++) {
		int u, v;
		cin >> u >> v;

		suc[u - 1].push_back(v - 1);
		pre[v - 1]++;
	}

	// ������ ������ ���� ���̴�.
	vector<int> result;
	deque<int> Q;

	// �����ڰ� �ϳ��� ���� ù ��� ���� ť�� push!
	for (int i = 0; i < N; i++)
		if (pre[i] == 0)
			Q.push_front(i);

	// ��� ��带 ���� ť�� �� ������!
	while (!Q.empty()) {
		int  u = Q.front();
		Q.pop_front();

		// ����� ������� push!
		result.push_back(u);

		for (auto next : suc[u]) {
			--pre[next];

			// �����ڰ� ���� ���ٸ�
			if (pre[next] == 0)
				// �׸��� ť�� �־����� �ش� ����� �۾� ����!
				Q.push_front(next);
		}
	}

	// ��� ����!
	int len = result.size();

	for (int i = 0; i < len; i++)
		cout << result[i] + 1 << ' ';

	cout << '\n';

	return 0;
}