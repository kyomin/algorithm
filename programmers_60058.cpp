#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string str) {
	stack<char> s;
	int len = str.size();
	int cnt = 0;

	for (int i = 0; i < len; i++) {
		char bracket = str[i];

		// 짝이 안 맞는 경우
		if (s.size() == 0 && bracket == ')')
			break;

		// 여는 괄호는 일단 넣기
		if (bracket == '(') {
			s.push(bracket);
			cnt += 1;
		}

		// 짝을 만나면
		if (s.size() != 0 && str[i] == ')') {
			s.pop();
			cnt += 1;
		}
	}

	if (s.size() == 0 && cnt == len)
		return true;
	else
		return false;
}

string solution(string p) {
	int len = p.size();

	if (len == 0)
		return p;

	if (isCorrect(p))
		return p;

	int open = 0;   // 여는 괄호
	int close = 0;  // 닫는 괄호

	string u = "";
	string v = "";
	int i = 0;

	while (i < len) {
		// 가장 먼저 찾은 균형잡힌 문자열일 경우
		if (open != 0 && close != 0 && open == close)
			break;

		if (p[i] == '(')
			open++;
		else
			close++;

		u += p[i];

		i++;
	}

	while (i < len) {
		v += p[i];

		i++;
	}

	// u가 올바른 괄호 문자열인지 검사한다.
	if (isCorrect(u))
		return u + solution(v);

	// u의 첫 번째와 마지막 문자를 제거하고 나머지 문자열의 괄호 방향을 뒤집는다.
	string newU = "";

	if (u.size() != 2) {
		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == '(')
				newU += ")";
			else
				newU += "(";
		}
	}

	return "(" + solution(v) + ')' + newU;
}