#include <string>
#include <stack>

using namespace std;

int solution(string s) {
	int answer = 0;
	int len = s.size();
	stack<char> st;

	for (int i = 0; i < len; i++) {
		if (st.empty()) {
			st.push(s[i]);
			continue;
		}

		if (st.top() == s[i]) {
			st.pop();
			continue;
		}

		st.push(s[i]);
	}

	if (st.empty())
		answer = 1;
	else
		answer = 0;

	return answer;
}