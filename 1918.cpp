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
		//operand(피연산자)
		if ('A' <= str[i] && str[i] <= 'Z')
			result += str[i];
		//operator(연산자)
		else {
			switch (str[i]) {
			case '(':
				s.push(str[i]);
				break;
			case '*':
			case '/':
				//우선순위 제일 높으므로 같은 기호들 pop
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					result += s.top();
					s.pop();
				}

				s.push(str[i]);

				break;
			case '+':
			case '-':
				//우선순위 같거나 높은 기호들 pop
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}

				s.push(str[i]);

				break;
			case ')':
				//'('가 나올 때까지 다 pop
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