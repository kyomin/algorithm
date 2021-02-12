#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	for (int t = 1; t <= 10; t++) {
		int len;
		string str;
		cin >> len;
		cin >> str;

		stack<char> st;
		int ans = 1;

		for (int i = 0; i < len; i++) {
			char ch = str[i];

			// 여는 괄호라면 스택에 넣어준다.
			if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
				st.push(ch);
				continue;
			}

			// 닫는 괄호인데, 여는 괄호가 없다면
			if (st.size() == 0) {
				ans = 0;
				break;
			}

			// 닫는 괄호인데, 짝이 안 맞는다면
			if (ch == ')' && st.top() != '(') {
				ans = 0;
				break;
			}

			if (ch == ']' && st.top() != '[') {
				ans = 0;
				break;
			}

			if (ch == '}' && st.top() != '{') {
				ans = 0;
				break;
			}

			if (ch == '>' && st.top() != '<') {
				ans = 0;
				break;
			}

			// 위의 검증을 통과했다면 짝이 맞는 경우이므로
			st.pop();
		}

		// 만일 위의 루프를 빠져 나왔는데, 여는 괄호가 아직 스택에 남아 있다면
		if (st.size() != 0)
			ans = 0;

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}