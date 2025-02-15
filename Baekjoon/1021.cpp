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

		// head���� �ش� �̾Ƴ� ���� �̵���Ű�µ� ����, ������ ���� �󸶳� �̵����� ���
		int left = cur - 1;
		int right = dq.size() - cur + 1;

		// �� ���� ���� ���ؼ� �۾��Ѵ�.
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