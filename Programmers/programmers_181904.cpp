#include <string>
#include <vector>
using namespace std;

string solution(string my_string, int m, int c) {
	vector<string> board;
	string answer = "";

	for (int start = 0; start < my_string.length(); start += m)
		board.push_back(my_string.substr(start, m));

	for (string str : board)
		answer += str[c - 1];

	return answer;
}