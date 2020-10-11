#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// �׽�Ʈ ���̽��� ��
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;	// ����� ����
		int K;	// ���� ������ ����
		int W;	// �ش��� �˰��� �ϴ� �ǹ� ��ȣ
		int time[1000];	// �� ���(�ǹ�)�� �۾� �ð�
		int pre[1000] = { 0, };	// �������� ����
		vector<int> suc[10000];	// �������� ��� ����Ʈ(���� ����Ʈ)

		cin >> N >> K;

		// �۾� �ð� ���� �Է�
		for (int i = 0; i < N; i++)
			cin >> time[i];

		// ���� ���� �Է�
		for (int i = 0; i < K; i++) {
			int u, v;
			cin >> u >> v;
			// �ε����� �����ֱ� ���� -1�� ���Ѵ�.
			suc[u - 1].push_back(v - 1);
			pre[v - 1]++;
		}

		cin >> W;	// Ÿ�� ��� ��ȣ �Է�
		W--;	// �ε����� �����ֱ� ����!

		// �ش� �ǹ��� ���� �����ϴ� �� �ɸ��� �ּ� �ð��� ��´�
		int result[1000] = { 0, };

		queue<int> Q;

		// �����ڰ� �ϳ��� ���� ������ ���� ť�� push
		for (int i = 0; i < N; i++)
			if (pre[i] == 0)
				Q.push(i);

		// W�� �ǹ��� �����ڰ� �ϳ��� ���� ������!
		while (pre[W] > 0) {
			int u = Q.front();
			Q.pop();

			// ��� ������ �ǹ��� �ּ� �Ǽ����۽ð��� ����!
			for (auto next : suc[u]) {
				result[next] = max(result[next], result[u] + time[u]);

				// �۾��� �������� ������ ������ �ϳ� ���δ�.
				--pre[next];

				// ���� ���� ��尡 ������ ����Ǿ� �ִ� ������ ���� �����
				if (pre[next] == 0)
					Q.push(next); // ���� �������� �����ϱ� ����!
			}
		}

		// ���� ����� ��ǥ �ǹ��� ���� �� �ɸ��� �ð��� ���ؾ� �Ѵ�.
		cout << result[W] + time[W] << '\n';
	}

	return 0;
}