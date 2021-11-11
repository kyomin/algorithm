#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack<string> s;

	while (true) {
		string str;
		getline(cin, str);

		if (str == "������ ����� ����")
			continue;

		if (str == "������ ����� ��")
			break;

		if (str == "����") {
			s.push(str);
			continue;
		}

		if (s.size() == 0) {
			s.push("����");
			s.push("����");
			continue;
		}

		s.pop();
	}

	if (s.size() == 0)
		cout << "�������� �����" << endl;
	else
		cout << "����" << endl;

	return 0;
}