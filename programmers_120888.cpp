#include <string>
#include <vector>
using namespace std;

string solution(string my_string) {
	string answer = "";
	int len = my_string.length();

	answer += my_string[0];

	for (int i = 1; i < len; i++) {
		bool flag = true;
		char ch = my_string[i];

		for (int j = 0; j < answer.length(); j++) {
			if (ch == answer[j]) {
				flag = false;
				break;
			}
		}

		if (flag)
			answer += ch;
	}

	return answer;
}