#include <string>
#include <vector>
using namespace std;

int solution(int order) {
	int answer = 0;
	string str = to_string(order);
	int len = str.length();

	for (int i = 0; i < len; i++) {
		char ch = str[i];

		if (ch == '3' || ch == '6' || ch == '9')
			answer++;
	}

	return answer;
}