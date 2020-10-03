#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
	int len = s.size();
	stack<char> st;

	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			st.push(s[i]);
			continue;
		}

		if (s[i] == ')') {
			if (st.empty())
				return false;

			st.pop();
		}
	}

	if (st.empty())
		return true;
	else
		return false;
}