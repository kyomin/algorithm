#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	deque<int> dq;
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int num;
			cin >> num;
			dq.push_back(num);
		} 
		else if (command == "pop") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (command == "size") {
			cout << dq.size() << '\n';
		}
		else if (command == "empty") {
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (command == "front") {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.front() << '\n';	
		}
		else if (command == "back") {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.back() << '\n';
		}
	}

	return 0;
}