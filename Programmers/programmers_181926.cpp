#include <string>
#include <vector>
using namespace std;

/*
	@param n		control에 따라 바뀌는 정수
	@param control		"w", "a", "s", "d"의 4개의 문자

	@return			규칙에 따라 n을 바꿨을 때 가장 마지막에 나오는 n의 값
*/
int solution(int n, string control) {
	int answer = n;
	int len = control.length();

	for (int i = 0; i < len; i++) {
		char ch = control[i];

		switch (ch) {
			case 'w': {
				answer += 1;
				break;
			}
			case 's': {
				answer -= 1;
				break;
			}
			case 'd': {
				answer += 10;
				break;
			}
			default: {
				answer -= 10;
			}
		}
	}

	return answer;
}