#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	deque<int> q;
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		string command;
		cin >> command;

		if (command == "push") {
			int num;
			cin >> num;

			q.push_back(num);
			continue;
		}

		if (command == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop_front();
			}
			else
				cout << -1 << '\n';

			continue;
		}

		if (command == "size") {
			cout << q.size() << '\n';
			continue;
		}

		if (command == "empty") {
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';

			continue;
		}

		if (command == "front") {
			if (!q.empty())
				cout << q.front() << '\n';
			else
				cout << -1 << '\n';

			continue;
		}

		if (command == "back") {
			if (!q.empty())
				cout << q.back() << '\n';
			else
				cout << -1 << '\n';

			continue;
		}
	}

	return 0;
}