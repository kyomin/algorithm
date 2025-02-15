#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack<string> s;

	while (true) {
		string str;
		getline(cin, str);

		if (str == "고무오리 디버깅 시작")
			continue;

		if (str == "고무오리 디버깅 끝")
			break;

		if (str == "문제") {
			s.push(str);
			continue;
		}

		if (s.size() == 0) {
			s.push("문제");
			s.push("문제");
			continue;
		}

		s.pop();
	}

	if (s.size() == 0)
		cout << "고무오리야 사랑해" << endl;
	else
		cout << "힝구" << endl;

	return 0;
}