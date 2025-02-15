#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(string my_string) {
	vector<string> answer;
	int len = my_string.length();

	for (int i = 0; i < len; i++)
		answer.push_back(my_string.substr(i, len));

	sort(answer.begin(), answer.end());

	return answer;
}