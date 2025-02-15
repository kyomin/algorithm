#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> Deque;
	vector<string> command;
	int N;
	cin >> N;

	// 명령어 담기!
	for (int i = 0; i <= N; i++) {
		string str;
		getline(cin, str);
		command.push_back(str);
	}

	// 명령어 처리!
	for (int i = 0; i <= N; i++) {
		if (command[i].substr(0, 6) == "push_b") {
			int len = command[i].size();
			string str = command[i].substr(10, len - 10);
			int n = atoi(str.c_str());

			Deque.push_back(n);
		}
		else if (command[i].substr(0, 6) == "push_f") {
			int len = command[i].size();
			string str = command[i].substr(11, len - 11);
			int n = atoi(str.c_str());

			// 덱이 초기 위치를 iter에 담고서
			vector<int>::iterator iter;
			iter = Deque.begin();

			// 삽입!
			Deque.insert(iter, n);
		}
		else if (command[i] == "pop_front") {
			if (Deque.size() == 0)
				cout << -1 << endl;
			else {
				cout << Deque[0] << endl;

				// 덱이 초기 위치를 iter에 담고서
				vector<int>::iterator iter;
				iter = Deque.begin();

				// 그 부분 삭제!
				Deque.erase(iter);
			}
		}
		else if (command[i] == "pop_back") {
			if (Deque.size() == 0)
				cout << -1 << endl;
			else{
				// 마지막 부분 출력하고
				cout << Deque[Deque.size() - 1] << endl;
				Deque.pop_back();
			}
		}
		else if (command[i] == "size")
			cout << Deque.size() << endl;
		else if (command[i] == "empty") { 
			// 비어있으면
			if (Deque.size() == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (command[i] == "front") {
			if (Deque.size() == 0)
				cout << -1 << endl;
			else
				cout << Deque[0] << endl;
		}
		else if (command[i] == "back") {
			if (Deque.size() == 0)
				cout << -1 << endl;
			else
				cout << Deque[Deque.size() - 1] << endl;
		}
	}

	return 0;
}