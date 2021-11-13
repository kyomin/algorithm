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

			// 여는 괄호라면
			if (ch == '(' || ch == '[') {
				s.push(ch);
				continue;
			}

			// 닫는 소괄호라면
			if (ch == ')') {
				// 스택이 빈 경우 짝지어질 게 없음
				if (s.size() == 0) {
					flag = false;
					break;
				}

				// 스택이 비지 않았는데 짝이 안 맞는다면
				if (s.top() != '(') {
					flag = false;
					break;
				}

				// 짝이 맞는 경우이다.
				s.pop();
			}

			// 닫는 대괄호라면
			if (ch == ']') {
				// 스택이 빈 경우 짝지어질 게 없음
				if (s.size() == 0) {
					flag = false;
					break;
				}

				// 스택이 비지 않았는데 짝이 안 맞는다면
				if (s.top() != '[') {
					flag = false;
					break;
				}

				// 짝이 맞는 경우이다.
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