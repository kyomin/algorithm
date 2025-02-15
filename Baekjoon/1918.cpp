#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> s;
	string result;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		//operand(�ǿ�����)
		if ('A' <= str[i] && str[i] <= 'Z')
			result += str[i];
		//operator(������)
		else {
			switch (str[i]) {
			case '(':
				s.push(str[i]);
				break;
			case '*':
			case '/':
				//�켱���� ���� �����Ƿ� ���� ��ȣ�� pop
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					result += s.top();
					s.pop();
				}

				s.push(str[i]);

				break;
			case '+':
			case '-':
				//�켱���� ���ų� ���� ��ȣ�� pop
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}

				s.push(str[i]);

				break;
			case ')':
				//'('�� ���� ������ �� pop
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}

				//'(' pop
				s.pop();

				break;
			}
		}
	}

	while (!s.empty()) {
		result += s.top();
		s.pop();
	}

	cout << result << "\n";

	return 0;
}