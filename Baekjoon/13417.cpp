#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		vector<char> card;
		deque<char> dq;
		int N;
		cin >> N;

		card.resize(N);
		for (int j = 0; j < N; j++)
			cin >> card[j];

		// ���� ������ ����
		dq.push_back(card[0]);
		for (int j = 0; j < N - 1; j++) {
			if (((int)card[j] < (int)card[j + 1]) || ((int)dq[0] < (int)card[j + 1]))
				dq.push_back(card[j + 1]);
			else 
				dq.push_front(card[j + 1]);
		}

		// ��� ���
		while (!dq.empty()) {
			cout << dq.front();
			dq.pop_front();
		}
		cout << '\n';
	}

	return 0;
}