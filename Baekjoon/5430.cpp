#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string commands;
		int N;
		string arr;
		cin >> commands;
		cin >> N;
		cin >> arr;

		deque<int> dq;
		string temp = "";
		int len = arr.length();
		for (int i = 0; i < len; i++) {
			if (arr[i] == '[')
				continue;
			else if ('0' <= arr[i] && arr[i] <= '9')
				temp += arr[i];
			else if (arr[i] == ',' || arr[i] == ']') {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool left = true;	// 뒤집어져있지 않으면 true
		bool flag = true;	// error가 아닐 경우 true
		len = commands.length();
		for (int i = 0; i < len; i++) {
			char command = commands[i];

			if (command == 'R')
				left = !left;
			else {
				if (dq.empty()) {
					flag = false;
					break;
				}

				if (left)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		if (flag) {
			if (left) {
				cout << '[';

				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}

				cout << ']' << endl;
			}
			else {
				cout << '[';

				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ',';
				}

				cout << ']' << endl;
			}
		}
		else {
			cout << "error" << endl;
		}
	}

	return 0;
}