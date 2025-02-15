#include <string>

using namespace std;

int solution(int n) {
	int answer = 0;
	string str = to_string(n);
	int len = str.size();

	for (int i = 0; i < len; i++)
		answer += (int)(str[i] - '0');
	
	return answer;
}