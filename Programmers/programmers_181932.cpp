#include <string>
#include <vector>
using namespace std;

string solution(string code) {
	string answer = "";
	int mode = 0;
	int len = code.length();

	for (int i = 0; i < len; i++) {
		char ch = code[i];

		// change mode
		if (ch == '1') {
			mode = mode == 0 ? 1 : 0;
			continue;
		}

		// mode == 1
		if (mode && i % 2 == 1) {
			answer += ch;
			continue;
		}

		// mode == 0
		if (!mode && i % 2 == 0) {
			answer += ch;
			continue;
		}
	}

	return answer.length() ? answer : "EMPTY";
}