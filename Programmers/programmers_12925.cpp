#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int len = s.size();
	
	if (s[0] == '+')
		answer = atoi(s.substr(1, len).c_str());
	else if (s[0] == '-')
		answer = atoi(s.substr(1, len).c_str()) * (-1);
	else
		answer = atoi(s.c_str());

	return answer;
}