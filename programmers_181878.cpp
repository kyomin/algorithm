#include <string>
#include <vector>
#include <cctype>
using namespace std;

int solution(string myString, string pat) {
	int answer = 0;
	int len1 = myString.length();
	int len2 = pat.length();

	// 서브 문자열이 더 긴 경우
	if (len2 > len1)
		return 0;

	// 편의를 위해 모두 소문자로 변환
	for (char &ch : myString)
		ch = tolower(ch);

	for (char &ch : pat)
		ch = tolower(ch);

	int end = len1 - len2;
	for (int start = 0; start <= end; start++) {
		string sub = myString.substr(start, len2);

		if (pat == sub) {
			answer = 1;
			break;
		}
	}

	return answer;
}