#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string solution(string str) {
	stack<char> left;
	stack<char> right;
	int length = str.length();

	for (int i = 0; i < length; i++) {
		char ch = str[i];

		if (ch == '<') {
			// Ŀ���� �� ���� �ƴ� ��
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (ch == '>') {
			// Ŀ���� �� ���� �ƴ� ��
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (ch == '-') {
			if (!left.empty()) {
				left.pop();
			}
		}
		else {
			left.push(ch);
		}
	}

	string leftStr = "";
	string rightStr = "";

	while (!left.empty()) {
		leftStr += left.top();
		left.pop();
	}

	while (!right.empty()) {
		rightStr += right.top();
		right.pop();
	}

	// ���ʸ� �������� �ȴ�.
	reverse(leftStr.begin(), leftStr.end());

	return leftStr + rightStr;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;

		cout << solution(str) << endl;
	}

	return 0;
}