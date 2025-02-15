#include <string>
#include <vector>
using namespace std;

int solution(string str1, string str2) {
	int answer = 2;
	int len1 = str1.length();
	int len2 = str2.length();

	if (len2 > len1)
		return 2;

	if (len1 == len2 && str1 != str2)
		return 2;

	for (int i = 0; i <= len1 - len2; i++) {
		if (str1.substr(i, len2) == str2) {
			answer = 1;
			break;
		}
	}

	return answer;
}