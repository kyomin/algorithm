#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	int len = s.size();
	
	for (int i = 0; i < len; i++) {
		char ch = s[i];
		int ch_num = (int)ch;

		if (ch == ' ') {
			answer += ch;
			continue;
		}

		if (isupper(ch)) {
			ch_num += n;

			if (ch_num > 90)
				ch_num = 65 + (ch_num - 91);

			ch = (char)ch_num;
			answer += ch;
			continue;
		}

		if (islower(ch)) {
			ch_num += n;

			if (ch_num > 122)
				ch_num = 97 + (ch_num - 123);

			ch = (char)ch_num;
			answer += ch;
			continue;
		}
	}

	return answer;
}