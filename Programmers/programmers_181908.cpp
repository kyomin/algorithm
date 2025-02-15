#include <string>
#include <vector>
using namespace std;

int solution(string my_string, string is_suffix) {
	int answer = 0;
	int len = my_string.length();

	for (int i = 0; i < len; i++) {
		string str = my_string.substr(i, len);

		if (str == is_suffix) {
			answer = 1;
			break;
		}
	}

	return answer;
}