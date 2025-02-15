#include <string>
#include <vector>
using namespace std;

int solution(string A, string B) {
	if (A == B)
		return 0;

	int answer = -1;
	int len = A.length();
	A = A + A;

	for (int i = 0; i < len; i++) {
		if (A.substr(i, len) == B) {
			answer = len - i;
			break;
		}
	}

	return answer;
}