#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	while (true) {
		int N, K, M;
		queue<int> q;

		cin >> N >> K >> M;

		if (N == 0 && K == 0 && M == 0)
			break;

		for (int n = 1; n <= N; n++)
			q.push(n);

		// 초기 M에 대해 처리
		for (int m = 0; m < M - 1; m++) {
			int n = q.front();
			q.pop();
			q.push(n);
		}

		q.pop();

		// K에 대해 처리
		while (q.size() > 1) {
			for (int k = 0; k < K - 1; k++) {
				int n = q.front();
				q.pop();
				q.push(n);
			}

			int n = q.front();
			q.pop();
		}

		cout << q.front() << '\n';
	}

	return 0;
}