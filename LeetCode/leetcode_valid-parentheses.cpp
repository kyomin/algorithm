#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	vector<char> parentheses = { '(', '{', '[' };

	bool foundElement(char ch) {
		for (int i = 0; i < parentheses.size(); i++)
			if (parentheses[i] == ch)
				return true;

		return false;
	}

	bool isValid(string s) {
		stack<char> st;

		for (int i = 0; i < s.size(); i++) {
			char ch = s[i];

			// 여는 괄호라면 그냥 넣어주기
			if (foundElement(ch)) {
				st.push(ch);
				continue;
			}

			// 닫는 괄호인 경우 처리
			if (st.size() == 0)
				return false;

			char open_parenthese = st.top();
			st.pop();

			if (ch == ')' && open_parenthese != '(') return false;
			if (ch == '}' && open_parenthese != '{') return false;
			if (ch == ']' && open_parenthese != '[') return false;
		}

		if (st.size() == 0) return true;
		else return false;
	}
};