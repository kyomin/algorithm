#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack<int> s;
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		string command;
		cin >> command;

		if (command == "push") {
			int num;
			cin >> num;
			s.push(num);
			continue;
		} 

		if (command == "pop") {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else
				cout << -1 << '\n';

			continue;
		}

		if (command == "size") {
			cout << s.size() << '\n';
			continue;
		}

		if (command == "empty") {
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';

			continue;
		}

		if (command == "top") {
			if (!s.empty())
				cout << s.top() << '\n';
			else
				cout << -1 << '\n';

			continue;
		}
	}

	return 0;
}