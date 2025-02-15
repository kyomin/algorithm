#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string my_string) {
	string answer = "";
	int len = my_string.length();

	for (int i = 0; i < len; i++) {
		char ch = my_string[i];

		if (islower(ch))
			answer += toupper(ch);
		else
			answer += tolower(ch);
	}

	return answer;
}