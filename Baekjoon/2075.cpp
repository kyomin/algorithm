#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;

			// ù ��° ���̶�� �׳� �־��ش�
			if (i == 0)
				pq.push(n);
			else {
				// �־��ְ� �� ���� �Ŀ�
				pq.push(n);

				// ��Ʈ pop => ���÷� �ּҰ��� �ɷ�����.
				pq.pop();
			}
		}
	}

	cout << pq.top() << '\n';

	return 0;
}