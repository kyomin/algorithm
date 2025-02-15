#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> Deque;
	vector<string> command;
	int N;
	cin >> N;

	// ��ɾ� ���!
	for (int i = 0; i <= N; i++) {
		string str;
		getline(cin, str);
		command.push_back(str);
	}

	// ��ɾ� ó��!
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

			// ���� �ʱ� ��ġ�� iter�� ���
			vector<int>::iterator iter;
			iter = Deque.begin();

			// ����!
			Deque.insert(iter, n);
		}
		else if (command[i] == "pop_front") {
			if (Deque.size() == 0)
				cout << -1 << endl;
			else {
				cout << Deque[0] << endl;

				// ���� �ʱ� ��ġ�� iter�� ���
				vector<int>::iterator iter;
				iter = Deque.begin();

				// �� �κ� ����!
				Deque.erase(iter);
			}
		}
		else if (command[i] == "pop_back") {
			if (Deque.size() == 0)
				cout << -1 << endl;
			else{
				// ������ �κ� ����ϰ�
				cout << Deque[Deque.size() - 1] << endl;
				Deque.pop_back();
			}
		}
		else if (command[i] == "size")
			cout << Deque.size() << endl;
		else if (command[i] == "empty") { 
			// ���������
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