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

	// ��ȣ ���� �־��ش�.
	for (int i = 0; i < n; i++)
		arr.push_back('(');

	for (int i = 0; i < n; i++)
		arr.push_back(')');

	do {
		string str(arr.begin(), arr.end());

		// �ùٸ� ��ȣ ���ڿ��̶��
		if (isCorrect(str))
			answer++;
	} while (next_permutation(arr.begin(), arr.end()));

	return answer;
}