#include <string>
#include <vector>
using namespace std;

int solution(int n) {
	int answer = 0;
	string str = to_string(n);
	int len = str.length();

	for (int i = 0; i < len; i++) {
		char ch = str[i];
		int num = (int)(ch - '0');

		answer += num;
	}

	return answer;
}