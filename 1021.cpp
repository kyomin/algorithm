#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	deque<int> dq;
	int answer = 0;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int idx;
		int cur = 1;
		cin >> idx;

		for (deque<int>::iterator iter = dq.begin(); iter < dq.end(); iter++) {
			if (*iter == idx) {
				break;
			}
			cur++;
		}

		// head까지 해당 뽑아낼 수를 이동시키는데 왼쪽, 오른쪽 각각 얼마나 이동할지 계산
		int left = cur - 1;
		int right = dq.size() - cur + 1;

		// 더 작은 것을 택해서 작업한다.
		if (left < right) {
			for (int i = 1; i <= left; i++) {
				int head = dq.front();
				dq.pop_front();

				dq.push_back(head);

				answer++;
			}

			dq.pop_front();
		}
		else {
			for (int i = 1; i <= right; i++) {
				int tail = dq.back();
				dq.pop_back();

				dq.push_front(tail);

				answer++;
			}

			dq.pop_front();
		}
	}

	cout << answer << '\n';

	return 0;
}