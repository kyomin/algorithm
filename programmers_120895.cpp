#include <string>
#include <vector>
using namespace std;

string solution(string my_string, int num1, int num2) {
	string answer = "";
	int len = my_string.length();

	for (int i = 0; i < len; i++) {
		if (i == num1) {
			answer += my_string[num2];
			continue;
		}

		if (i == num2) {
			answer += my_string[num1];
			continue;
		}

		answer += my_string[i];
	}

	return answer;
}