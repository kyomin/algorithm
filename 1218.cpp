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

			// ���� ��ȣ��� ���ÿ� �־��ش�.
			if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
				st.push(ch);
				continue;
			}

			// �ݴ� ��ȣ�ε�, ���� ��ȣ�� ���ٸ�
			if (st.size() == 0) {
				ans = 0;
				break;
			}

			// �ݴ� ��ȣ�ε�, ¦�� �� �´´ٸ�
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

			// ���� ������ ����ߴٸ� ¦�� �´� ����̹Ƿ�
			st.pop();
		}

		// ���� ���� ������ ���� ���Դµ�, ���� ��ȣ�� ���� ���ÿ� ���� �ִٸ�
		if (st.size() != 0)
			ans = 0;

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}