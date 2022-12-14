#include <string>
#include <vector>
using namespace std;

int solution(int num, int k) {
	int answer = -1;
	string str = to_string(num);
	int len = str.length();

	for (int i = 0; i < len; i++) {
		char ch = str[i];
		int n = (int)(ch - '0');

		if (n == k) {
			answer = i + 1;
			break;
		}
	}

	return answer;
}