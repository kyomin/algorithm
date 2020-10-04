#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<char> arr;

bool isCorrect(string s) {
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

int solution(int n) {
	int answer = 0;

	// 괄호 쌍을 넣어준다.
	for (int i = 0; i < n; i++)
		arr.push_back('(');

	for (int i = 0; i < n; i++)
		arr.push_back(')');

	do {
		string str(arr.begin(), arr.end());

		// 올바른 괄호 문자열이라면
		if (isCorrect(str))
			answer++;
	} while (next_permutation(arr.begin(), arr.end()));

	return answer;
}