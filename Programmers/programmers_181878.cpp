#include <string>
#include <vector>
#include <cctype>
using namespace std;

int solution(string myString, string pat) {
	int answer = 0;
	int len1 = myString.length();
	int len2 = pat.length();

	// ���� ���ڿ��� �� �� ���
	if (len2 > len1)
		return 0;

	// ���Ǹ� ���� ��� �ҹ��ڷ� ��ȯ
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