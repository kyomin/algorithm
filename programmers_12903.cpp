#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";

	int len = s.size();

	int index = len / 2;

	if (len % 2 == 1)
		answer = s.substr(index, 1);
	else
		answer = s.substr(index - 1, 2);

	return answer;
}