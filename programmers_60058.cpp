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

		// ¦�� �� �´� ���
		if (s.size() == 0 && bracket == ')')
			break;

		// ���� ��ȣ�� �ϴ� �ֱ�
		if (bracket == '(') {
			s.push(bracket);
			cnt += 1;
		}

		// ¦�� ������
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

	int open = 0;   // ���� ��ȣ
	int close = 0;  // �ݴ� ��ȣ

	string u = "";
	string v = "";
	int i = 0;

	while (i < len) {
		// ���� ���� ã�� �������� ���ڿ��� ���
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

	// u�� �ùٸ� ��ȣ ���ڿ����� �˻��Ѵ�.
	if (isCorrect(u))
		return u + solution(v);

	// u�� ù ��°�� ������ ���ڸ� �����ϰ� ������ ���ڿ��� ��ȣ ������ �����´�.
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