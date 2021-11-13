#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	while (true) {
		stack<char> s;
		string str;
		getline(cin, str);

		if (str == ".")
			break;

		int len = str.length();
		bool flag = true;

		for (int i = 0; i < len; i++) {
			char ch = str[i];

			// ���� ��ȣ���
			if (ch == '(' || ch == '[') {
				s.push(ch);
				continue;
			}

			// �ݴ� �Ұ�ȣ���
			if (ch == ')') {
				// ������ �� ��� ¦������ �� ����
				if (s.size() == 0) {
					flag = false;
					break;
				}

				// ������ ���� �ʾҴµ� ¦�� �� �´´ٸ�
				if (s.top() != '(') {
					flag = false;
					break;
				}

				// ¦�� �´� ����̴�.
				s.pop();
			}

			// �ݴ� ���ȣ���
			if (ch == ']') {
				// ������ �� ��� ¦������ �� ����
				if (s.size() == 0) {
					flag = false;
					break;
				}

				// ������ ���� �ʾҴµ� ¦�� �� �´´ٸ�
				if (s.top() != '[') {
					flag = false;
					break;
				}

				// ¦�� �´� ����̴�.
				s.pop();
			}
		}

		if (flag && s.size() == 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}