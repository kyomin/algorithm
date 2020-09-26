#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solution(string str) {
	stack<char> parentheses;
	stack<int> num;

	int len = str.size();
	bool isClosed = false;	// 현재 닫는 괄호가 연속인가?
	bool rightParentheses = true;
	int ans = 0;

	for (int i = 0; i < len; i++) {
		char c = str[i];

		// 여는 괄호라면 그냥 넣어주기
		if (c == '(' || c == '[') {
			parentheses.push(c);
			isClosed = false;
			continue;
		}

		if (c == ']') {
			// 짝을 맞춰야 되는데 크기가 0이라면
			if (parentheses.size() == 0) {
				rightParentheses = false;
				break;
			}

			// 짝이 안 맞는다면
			if (parentheses.top() != '[') {
				rightParentheses = false;
				break;
			}

			// 연속으로 닫는 괄호가 나온 것이 아니라면
			if (!isClosed) {
				parentheses.pop();

				if (parentheses.size() != 0) {
					num.push(3);
					isClosed = true;
				}
				else {
					int sum = 0;

					if (num.size() == 0) {
						ans += 3;
					}
					else {
						while (num.size() != 0) {
							sum += num.top();
							num.pop();
						}

						ans += (3 * sum);
					}
				}
			}
			else {  // 연속으로 닫는 괄호가 나온 것이라면
				parentheses.pop();

				if (parentheses.size() != 0) {
					int n = num.top();
					num.pop();
					num.push(n * 3);
				}
				else {
					int sum = 0;

					if (num.size() == 0) {
						ans += 3;
					}
					else {
						while (num.size() != 0) {
							sum += num.top();
							num.pop();
						}

						ans += (3 * sum);
					}
				}
			}

			continue;
		}

		if (c == ')') {
			// 짝을 맞춰야 되는데 크기가 0이라면
			if (parentheses.size() == 0) {
				rightParentheses = false;
				break;
			}

			// 짝이 안 맞는다면
			if (parentheses.top() != '(') {
				rightParentheses = false;
				break;
			}

			// 연속으로 닫는 괄호가 나온 것이 아니라면
			if (!isClosed) {
				parentheses.pop();

				if (parentheses.size() != 0) {
					num.push(2);
					isClosed = true;
				}
				else {
					int sum = 0;

					if (num.size() == 0) {
						ans += 2;
					}
					else {
						while (num.size() != 0) {
							sum += num.top();
							num.pop();
						}

						ans += (2 * sum);
					}
				}
			}
			else {  // 연속으로 닫는 괄호가 나온 것이라면
				parentheses.pop();

				if (parentheses.size() != 0) {
					int n = num.top();
					num.pop();
					num.push(n * 2);
				}
				else {
					int sum = 0;

					if (num.size() == 0) {
						ans += 2;
					}
					else {
						while (num.size() != 0) {
							sum += num.top();
							num.pop();
						}

						ans += (2 * sum);
					}
				}
			}

			continue;
		}
	}

	// 다 돌렸는데도 아직 스택에 남아 있다면
	if (parentheses.size() != 0)
		return 0;

	if (!rightParentheses)
		return 0;
	else
		return ans;
}

int main() {
	string str;
	cin >> str;

	cout << solution(str) << endl;
	
	return 0;
}